#include<stdio.h>
struct syohin_data {
	char name[20];
	int tanka;
	int kosuu;
};
main()
{
	struct syohin_data syohin[3] = { {"エンピツ",30,5}
	,{"ケシゴム",50,2},{"フデバコ",500,3}};
	struct syohin_data* p;
	p = syohin;
	//p = &syohin[0];
	//p = syohin[0].name;
	//p = &syohin[0].name[0];
	int i;
	for (i = 0; i < 3; i++) {
		printf("商品名:%s\t", p->name);
		printf("単価:%d\t", p->tanka);
		printf("個数:%d\t", p->kosuu);
		printf("金額:￥%d\n", p->tanka * p->kosuu);
		p++;
	}
}