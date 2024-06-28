#include<stdio.h>
main()
{
				// 配列の初期化
	int i, a[5], b[3] = { 31,67,97 };
	// ループ処理で配列aの各要素に数値を代入する
	for (i = 0; i < 5; i++) {
		a[i] = (i+1)*10;
	}
	for (i = 0; i < 5; i++) {
		printf("a[%d]=%d\n", i, a[i]);
	}
	for (i = 0; i < 3; i++) {
		printf("b[%d]=%d\n", i, b[i]);
	}
}