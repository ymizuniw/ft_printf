本家のバッファ管理をスルーして逐次出力、va_copy有効活用で実装する。
ワークフローをステップバイステップで考える。

前提を考える
・va_argの対象となるのは型が明確な引数のみ。
・よって、型が唯一（const char *）に指定されている第一引数に対してparse_formatを行い、
・<%~conversion>を1単位とする変換ブロックがいくつ必要かをカウント(count_block)して、
・t_format型の配列をmalloc(sizeof(t_format)*count_block)する。

・パースした情報を各tokenに対応したt_formatに格納して、その情報を元に、va_argにより与えられた具体的な引数にformatを適用して空白や符号を含めて文字列に変換するのがapply_format。→この構文解析がワンポイント



✅ なぜ i + 1 を返していたのか？
parse_format() は % から d まで何文字読んだかを i に記録

%5.2d → i == 4、s[i] == 'd'

呼び出し元では s += i + 1 で次の文字に進んでいた

つまり return (i + 1) は、「このトークンが何文字分だったか」を示すためのものでした

✅ しかし、今の新構成では？
tokenize_format() で t_token[] に切り分け済み

各トークンには .str と .format がある

i という読み取り位置の概念は 既に使われた後

dispatch_*_format() は トークンを1つ処理するだけ なので i + 1 は不要




・
□出力用のva_arg
□

ワークフローを書く

tokenize_all(const char *format) // 与えられたconst char *formatを「プレーンテキスト」と「変換ブロック」のトークンに分ける
↓
t_token.plain, t_token.conv を持つ t_tokenに格納する。
↓
apply_format(t_token.conv, arg)
↓
簡易バッファ使用しつつwriteで出力





Basic flow（only for mandatory）
・tokenize()
・％を検知して、次の文字が変換子ならstartインデックスを進めて、ここまでのフォーマットの情報をトークンとして切り出して、新しいノードを取得して情報を代入していく。（ボーナスでは、この段階でフラグ、幅、精度、幅と精度の動的な取得も同時に処理する）
・もし、format[start] の初期値が%で無いならば、%かnullが来るまでplace indexを進めて、来たらトークンとしてそれまでの情報を切り出して新しいノードを取得して値をセットする。このとき、切り出すのは文字列そのものであり、トークンの中の文字列用の変数strなどにsubstrやstrndupを利用して代入する。
・％が来る限りは、このステップのループを継続して、トークンごとにノードが確保され、フラグやspecの情報が保存されていることを確認する。


・parse_format(単にフォーマットをフラグにセットする、という話ではない。競合する条件を明らかにして、正しい出力を得られるような分岐を記述する必要がある。)
・+, space -> if (num < 0)のとき「考慮しない」方針か、「常に絶対値を文字列として取得して、numの情報を元に符号を付与する」方針にするか。後者の方が一貫性があって実装としては適切な気がする。ここは直さないと行けない。
・すべての条件を明らかにできれば、最終出力に必要なヒープ領域の容量もわかるので、malloc して出力用の文字列を確保する形式にする。
・# -> prefix,　x, Xの場合のみ有効。if ((spec == x or spec == X) && (# == 1)), # = 1, else # = 0.また、prefix == 1 ならば、flag_plus, flag_space = 0にセット。
ここでも、前の修正が活きるはず。数値が来たときに絶対値を取得しておけば、それをx,Xに変換したときに符号処理を考えなくて良くなる。
・precision ->
//整数：　精度が引数の数値の桁数より大きい場合は、数値の頭に(precision - word_len)個の0をつけるようにstrjoin、もしくはmalloc -> strlcatし、word_len = precision に更新する。この更新を踏まえて、widthとの比較に望む。また、if (precision = 1), flag_zero = 0.
//文字列: 精度が引数の文字列の長さより小さい場合、常に右側を切り捨てる。word_len をprecisionに更新する。精度 > 文字列長の場合は、特に何もしない。
・width
/分岐1: もし、幅が引数の文字列長より大きいならば、width が有効なので次の分岐に入る。
//分岐2: flag_minus = 1ならば、文字列の左側にpaddingを行い、flag_minus = 0 ならば、右側にパディングを行うが、prefixや符号の処理が残っているため、まだ文字列の連結はせず、padding_left or padding_rightのフラグを立てておく。列挙体で、t_width {FRONT, BACK}のようにセットするなど。padding_printなどの関数で、この条件を使用する。

・引数をパースするタイミングは、各トークンのformatの適用時で問題ないはず。
・トークンごとのアウトプット用の文字列を確保する。char *output_token = (char *)malloc ((char *) * (prefix(0 - 2) + sign(0 - 1) + max [{width} {precision} {word_len}]))
//ここまでで、フラグの情報は「すべて整理されている」はずなので、問題なく、padding_left, prefix, 符号、（パースされた）引数値、padding_rightを、output_tokenに配置することができる。
