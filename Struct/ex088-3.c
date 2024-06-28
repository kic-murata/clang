#include<stdio.h>
#include<string.h>
typedef struct {
	char name[20];
	int tanka;
} 商品データ;
typedef int 整数;
main()
{
	整数 a = 10;
	printf("a=%d\n", a);
	商品データ syohin1, syohin2;
	strcpy(syohin1.name, "エンピツ");
	syohin1.tanka = 30;
	syohin2 = syohin1;
	printf("syohin1.name=%s\n", syohin1.name);
	printf("syohin1.tanka=%d\n", syohin1.tanka);
	printf("syohin2.name=%s\n", syohin2.name);
	printf("syohin2.tanka=%d\n", syohin2.tanka);
}