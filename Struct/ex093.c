#include<stdio.h>
struct syohin_data {
	char name[20];
	int tanka;
	int kosuu;
};
main()
{
	struct syohin_data syohin[3] = { {"�G���s�c",30,5}
	,{"�P�V�S��",50,2},{"�t�f�o�R",500,3}};
	struct syohin_data* p;
	p = syohin;
	//p = &syohin[0];
	//p = syohin[0].name;
	//p = &syohin[0].name[0];
	int i;
	for (i = 0; i < 3; i++) {
		printf("���i��:%s\t", p->name);
		printf("�P��:%d\t", p->tanka);
		printf("��:%d\t", p->kosuu);
		printf("���z:��%d\n", p->tanka * p->kosuu);
		p++;
	}
}