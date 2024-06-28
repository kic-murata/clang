#include<stdio.h>
main()
{
	int a, b, c, ret;
	printf("数値を３つ入力:");
	ret = scanf("%d%d%d", &a, &b, &c);
	printf("ret:%d\ta:%d\tb:%d\tc:%d\n", ret, a, b, c);

	printf("数値を一つ入力(Ctrl+Zで終了）：");
	while(scanf("%d", &a)　!=　EOF){
		printf("数値：%d\n", a);
		printf("数値を一つ入力(Ctrl+Zで終了）：");
	}
}