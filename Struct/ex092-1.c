#include<stdio.h>
struct syohin_data {
	char name[20];
	int tanka;
	int kosuu;
};
main()
{
	struct syohin_data pencil = { "�G���s�c",30,5 };
	struct syohin_data eraser = { "�P�V�S��",50,2 };
	struct syohin_data pencase = { "�t�f�o�R",500,3 };
	printf("���i��:%s\t", pencil.name);
	printf("�P��:%d\t", pencil.tanka);
	printf("��:%d\n", pencil.kosuu);
	printf("���i��:%s\t", eraser.name);
	printf("�P��:%d\t", eraser.tanka);
	printf("��:%d\n", eraser.kosuu);
	printf("���i��:%s\t", pencase.name);
	printf("�P��:%d\t", pencase.tanka);
	printf("��:%d\n", pencase.kosuu);

}