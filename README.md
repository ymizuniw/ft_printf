本家のバッファ管理をスルーして逐次出力、va_copy有効活用で実装する。
ワークフローをステップバイステップで考える。

前提を考える
・va_argの対象となるのは型が明確な引数のみ。
・よって、型が唯一（const char *）に指定されている第一引数に対してparse_formatを行い、
・<%~conversion>を1単位とする変換ブロックがいくつ必要かをカウント(count_block)して、
・t_format型の配列をmalloc(sizeof(t_format)*count_block)する。

・パースした情報を各tokenに対応したt_formatに格納して、その情報を元に、va_argにより与えられた具体的な引数にformatを適用して空白や符号を含めて文字列に変換するのがapply_format。→この構文解析がワンポイント

ワークフローを書く

tokenize_all(const char *format) // 与えられたconst char *formatを「プレーンテキスト」と「変換ブロック」のトークンに分ける
↓
t_token.plain, t_token.conv を持つ t_tokenに格納する。
↓
apply_format(t_token.conv, arg)
↓
簡易バッファ使用しつつwriteで出力



□特殊ケース
・char 出力で\0の時は1を返しているか。
・
□エラーケース
・tokenize出来ないフォーマットを渡された時や、引数が不正で変換に失敗した場合にreturn (-1)で統一されていること。
・メモリリークが起きていないことを確認。また、すべてのmalloc に対して失敗ケースを強制的に作り出す関数を利用して、
以下のコマンドを実行する。
>clang -fsanitize=address -g -o program main.c
>./program

・flag_hasか、t_bool(is_upper)か、何かが間違っている。
→set_cout_prefixのあたりで、&& f->flag_hashという条件がある。これが怪しい。フラグの競合条件を見直す。
→output_listに渡された時点で、token->parsed_arg のポインタの指す文字列は2A。パースargsが怪しい。
→parse_argsの中身、arg_to_specが怪しい。arg_to_specに渡された時点では、x指定、
→ == と = の使い間違い。特定！

・パッディングが未出力→set_outputstrで出力文字列が正しく構成できていない　or　出力文字数が正しく設定されていない。
→後者。set_ouput_str内でlens->total += buf_index(padding込みの文字列長プラス終端文字分)のように、正しく加算されていなかった。
これのせいで、output_tokenが正しい出力文字数を受け取れず、出力にずれが生じていた。

・符号表現に差異がある。-が正しく出力されていない。フラグの未更新が問題かもしれない。
1. %010d 指定で負数が正数、正数が負数になるバグ？負数から負数は問題なし。
→%-10dでも同じ現象を観測。
→単体テストは通過。複数の出力がある際にフラグが初期化できていいない可能性が増加。
→%10.5dでバグを観測。ここで問題が生じている可能性がある。
→%10.5dの単体テストにて、num = -1234,負数の時に符号が消えている。原因を追求する。
→ケース候補
・itoa_absで絶対値に変換後、マイナスを付けるロジックが起動していない。フラグが反映されていないか、そもそもnum < 0ケースでマイナスを付与するロジックと接続していないか。
具体関数
set_count_signでsignをセットする条件がis_negativeであること。
→見たところ、（フラグ）∧（is_negative）以外の条件で-がセットされていない。
→条件を修正したところ、問題解決！

・%iケースにて、%dのテストに連続して行うと正数に負の符号がつくバグが発生。フラグ管理の問題ではないかと思われる。初期化対象にis_negativeが含まれているか確認。
→初期化対象にis_negativeが含まれていない。追加したところ、バグが修正された。解決！

・UNSIGNEDのケースにて、空白とゼロがバッファが埋め尽くされるバグが発生。parse_argsが機能していないように見える。utoaを確認。
→indexのインクリメントが欠落。各桁を逆順に格納したのに、返り値ようのバッファにその順番のまま詰めていた。修正したところ、動作が正常に戻った。解決！

・%%のケースにて、%-5%の出力にパッディングが含まれている。動作の模倣という観点からは、すべてのフラグを無効にして%のみを出力する仕様にする必要がある。
→spec != '%' を条件に各種フラグの出力などを行うように条件を変更すべきかもしれない。％ならば無条件でTXTに送るというのも、ありか。既に幅や精度を確保してしまったという状態にならないように、事前に弾いて置く必要がある。
→manage_flag_specにて、spec == '%' ならば幅と精度を0に設定するように修正。→正常出力。　解決！

・ダブルフリーを検知。単体テストでは問題ないが、複数になると発生する様子。

1.UNSIGNED, HEXAl,HEXAu, PERCENT→正常
2.CHAR, STRING, DECIMAL, INTEGER →ダブルフリー検知
3.CHAR, STRING, DECIMAL →ダブルフリー検知
4.CHAR, STRING, INTEGER →正常
5.CHAR, INTEGER →正常
6.CHAR, STRING, DECIMAL →ダブルフリー検知
7.CHAR, DECIMAL →正常
8.STRING, DECIMAL→セグフォ
9.CHAR, STRING →正常
10.without STRING →ダブルフリー検知
11.without DECIMAL →ダブルフリー検知
12.without STRING AND DECIMAL →正常


原因候補
・apply_formatが失敗したときのfreeは正確か？
・無条件のフリーがダブっていないか？
・すべてのフリーについて、どこで、なぜフリーしているのかを注釈。

tokenize_format
|
|--initialize_token-if(!token->format)-free(token)
|
|--if(!token)-ft_lstclear(&head, free_token)
|--if(!node)|-free_token(token)
|           |-ft_lstclear(&head, free_token)
|
|--|--get_block_token-if(!token->block)-free(token)
|  |--get_conv_token|-if(!f)-free_token(token)
|                   |-if(f->spec == 0)-free(token)

apply_format
|
|--if(!output_str)-free(parts.precision), return.
|--free(parts.precision)
|


検討
・フラグ情報は参照されては行けない場合がある。精度が指定されていないのに初期化した値を精度とみなしては行けない。
→精度指定を入れた場合の挙動をgdbで調べれば良い。break をparse_formatあたりに入れて挙動を確認する。

・utils関数のファイルを除いて、一つのファイルには一つの関数を割り当てる。staticによる補助関数は除く。
→どの関数が何をしているのかわからないと、一時に修正を加えたときに以前の構造との整合性が崩れることがある。
・ '-' がある場合、0 は無効?
→反映済み。フラグマネージメント関数を実装した。コンフリクトも解消する関数を追加した。

・nilの出力はptoaに任せてある。


MY FT_PRINTF LOGIC:
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


追記：ボーナスのフローは変更が加えられた。
・可変長引数取得開始
・リスト一周目: フォーマットをトークン化（リスト・ノード取得）
・リスト二周目: 各トークンのフォーマットをパース
・リスト三周目:

ft_printf(fmt, ...)
│
├── va_start(ap, fmt)
│
├── tokenize_format(fmt, ap)→リストノード取得
│    ├── get_conv_token()
│    └── get_block_token()
│
├── parse_format(tokens)→ノードを進めながらトークンごとのフォーマットをパース
│
├── parse_args(tokens, ap_args)→ノードを進めながら引数をパースしてトークンごとに格納
│    └── va_arg() による width / precision / main arg の取得
│
├── apply_format(tokens)→ノードを進めながらトークンごとにフォーマットを適用
│    └── format に応じて出力文字列構築
│
├── output()  // バッファ出力関数→ノードを進めながらトークンごとに最終出力値を出力
│
├── cleanup() // トークンリストや一時メモリの解放→すべてのノードと要素を開放
│
└── va_end(ap)



ディレクトリ構成からこのフローが辿れることを確認する。
・main.c
・ft_printf.c
・・tokenize
・・・parse_format, parse_format_utils
・parse_args, parse_args_utils
・apply_format
・output

構造の明確さを優先して、これらをft_printfから操作する。
