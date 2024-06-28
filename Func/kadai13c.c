#include<stdio.h>
void swap(int* a, int* b);
main()
{
	int a, b;
	printf("整数を２つ入力：");
	scanf("%d%d", &a, &b);
	printf("関数実行前の値：\na=%d\tb=%d\n", a, b);
	swap(&a, &b); //関数を実行
	printf("関数実行後の値：\na=%d\tb=%d\n", a, b);
}
void swap(int* a, int* b) {
	int w;
	w = *a;
	*a = *b;
	*b = w;
}