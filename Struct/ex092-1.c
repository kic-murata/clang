#include<stdio.h>
struct syohin_data {
	char name[20];
	int tanka;
	int kosuu;
};
main()
{
	struct syohin_data pencil = { "エンピツ",30,5 };
	struct syohin_data eraser = { "ケシゴム",50,2 };
	struct syohin_data pencase = { "フデバコ",500,3 };
	printf("商品名:%s\t", pencil.name);
	printf("単価:%d\t", pencil.tanka);
	printf("個数:%d\n", pencil.kosuu);
	printf("商品名:%s\t", eraser.name);
	printf("単価:%d\t", eraser.tanka);
	printf("個数:%d\n", eraser.kosuu);
	printf("商品名:%s\t", pencase.name);
	printf("単価:%d\t", pencase.tanka);
	printf("個数:%d\n", pencase.kosuu);

}