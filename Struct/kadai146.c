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
	struct fruit* p;
	p = kudamono;
	for (i = 0; i < 3; i++) {
		(p + i)->total = (p + i)->price * (p + i)->number;
		total += (p + i)->total;
		printf("���i���F\t%s\n", (p + i)->name);
		printf("���i�F\t\t%d�~", (p + i)->price);
		printf("\t\t���E�ߓx�F\t%d�|�C���g\n", (p + i)->point);
		printf("\n���F\t\t%d��", (p + i)->number);
		printf("\t\t���z�F\t\t��%d-\n\n", (p + i)->total);
	}
	printf("���v���z�@���@��%d-\n",total);
}