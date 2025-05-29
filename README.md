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
