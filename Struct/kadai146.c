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
		printf("商品名：\t%s\n", (p + i)->name);
		printf("価格：\t\t%d円", (p + i)->price);
		printf("\t\tお薦め度：\t%dポイント\n", (p + i)->point);
		printf("\n個数：\t\t%d個", (p + i)->number);
		printf("\t\t金額：\t\t￥%d-\n\n", (p + i)->total);
	}
	printf("合計金額　＝　￥%d-\n",total);
}