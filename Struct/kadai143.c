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
	printf("商品名：\t%s\n", kudamono.name);
	printf("価格：\t\t%d円\n", kudamono.price);
	printf("お薦め度：\t");
	for (i = 0; i < kudamono.point; i++) {
		printf("★ ");
	}
	printf("\n個数：\t\t%d個\n", kudamono.number);
	printf("金額：\t\t￥%d-\n", kudamono.total);
}