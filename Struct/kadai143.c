#include<stdio.h>
struct fruit {
	char name[30];
	int price, point, number, total;
};
main()
{
	int i;
	struct fruit kudamono = { "peach",300,5,3,0 };
	kudamono.total = kudamono.price * kudamono.number;
	printf("���i���F\t%s\n", kudamono.name);
	printf("���i�F\t\t%d�~\n", kudamono.price);
	printf("���E�ߓx�F\t");
	for (i = 0; i < kudamono.point; i++) {
		printf("�� ");
	}
	printf("\n���F\t\t%d��\n", kudamono.number);
	printf("���z�F\t\t��%d-\n", kudamono.total);
}