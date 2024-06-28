#include<stdio.h>
main()
{
	// 整数型変数iと要素数5つの配列dataを宣言
	int i, data[5];
	// iを0～4に変化（配列の添え字用）
	for (i = 0; i < 5; i++) {
		// 入力を促す
		printf("配列data[%d]=", i);
		// 配列dataの添え字を変更して入力
		scanf("%d", &data[i]);
	}
	for (i = 0; i < 5; i++) {
		// 添え字を0～4まで変更しながら表示
		printf("data[%d]=%d\n", i, data[i]);
	}
}