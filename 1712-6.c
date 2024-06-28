#include<stdio.h>
#include<ctype.h>
int main(void)
{
	// 明治～平成までの
	char gengo[][7] = { "Meiji","Taisho","Showa","Heisei" };
	char buf[80], * p, q;
	int i, j;
	for (i = 0; i < 4; i++) {
		printf("gengo[%d]（%s）のアドレス：%d\n", i, gengo[i],(int)gengo[i]%1000);
	}

	// 文字型配列gengoの２番目の文字列を表示
	printf("%s\n", gengo[2]);
	// 文字型配列gengoの１番目の文字列の先頭から3番目の文字を表示
	printf("%c\n", gengo[1][3]);
	// ポインタ変数pに文字型配列gengoの0番目の文字列のアドレスを代入
	p = gengo[0];
	// 文字列の先頭から3番目の文字から文字列を表示
	printf("%s\n", p + 3);
	// 文字列の先頭から1番目の文字を文字型変数qに代入
	q = *(p + 1);
	// 文字型変数qに格納された文字コードに＋１する
	q++;
	printf("%c\n", q);

	j = 0;
	// iが1～3まで変化するようにループ
	for (i = 1; i < 4; i++) {
		// ポインタ変数pに文字型配列のi番目の文字列のアドレスを代入
		p = gengo[i];
		// 文字列を一文字ずつチェックして\0が出てくるまでループ
		while (*p != '\0') {
			// ポインタ変数pのアドレスが指す文字が16進数で使用される文字のときは真
			if (isxdigit(*p)) {
				// 真のときに、文字型配列bufにその文字を格納
				buf[j] = *p;
				// 配列bufの添え字の番号を+1する
				j++;
			}
			// ポインタ変数内のアドレスをひとつ進める（次の文字へ）
			p++;
		}
	}
	// 文字型配列bufの最後の要素に\0（文字列の終端）を代入
	buf[j] = '\0';
	// 文字型配列bufの内容を文字列として表示
	printf("%s\n", buf);

	return 0;
}