#include<stdio.h>
main()
{
	float fn1, fn2, fn3;
	printf("1つめの実数：");
	scanf("%f", &fn1);
	printf("2つめの実数：");
	scanf("%f", &fn2);
	printf("3つめの実数：");
	scanf("%f", &fn3);
	printf("合計＝%f 平均=%f\n", fn1+fn2+fn3, (fn1+fn2+fn3)/3 );
}