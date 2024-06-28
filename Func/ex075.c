#include<stdio.h>
void shisoku(int x, int y, int* wa, int* sa, int* sk, int* syo,int *ama);
main()
{
	int a, b, c, d, e, f, g;
	printf("計算前\n和:%d 差:%d 積:%d 商:%d 余:%d\n\n", c, d, e, f, g);
	printf("数値1？");
	scanf("%d", &a);
	printf("数値2？");
	scanf("%d", &b);
	shisoku(a, b, &c, &d, &e, &f, &g);
	puts("数値１と数値２の四則演算");
	printf("和:%d 差:%d 積:%d 商:%d 余:%d\n", c, d, e, f, g);
}
void shisoku(int x, int y, int* wa, int* sa, int* sk, int* syo,int *ama) {
	*wa = x + y;
	*sa = x - y;
	*sk = x * y;
	*syo = x / y;
	*ama = x % y;
}