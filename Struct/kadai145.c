#include<stdio.h>
struct fruit {
	char name[30];
	int price, point, number, total;
};
main()
{
	int i, j, total = 0;
	struct fruit kudamono[] = { {"peach",300,5,3,0},
		{"grape",200,4,10,0},{"watermelon",1500,5,8,0} };
	for (i = 0; i < 3; i++) {
		kudamono[i].total = kudamono[i].price * kudamono[i].number;
		total += kudamono[i].total;
		printf("���i���F\t%s\n", kudamono[i].name);
		printf("���i�F\t\t%d�~", kudamono[i].price);
		printf("\t\t���E�ߓx�F\t");
		for (j = 0; j < kudamono[i].point; j++) {
			printf("�� ");
		}
		printf("\n���F\t\t%d��", kudamono[i].number);
		printf("\t\t���z�F\t\t��%d-\n\n", kudamono[i].total);
	}
	printf("���v���z�@���@��%d-\n",total);
}