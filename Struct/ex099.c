#include<stdio.h>
#define DATA_END -1
struct ken {
	int code;
	char name[20];
	struct ken* next;
};
main()
{
	struct ken ken_data[] = {{1,"北海道",NULL},{2,"青森県",NULL},{3,"岩手県",NULL},
		{4,"宮城県",NULL},{5,"秋田県",NULL},{6,"山形県",NULL},{7,"福島県",NULL},
		{DATA_END,"",NULL} };
	struct ken* p, * wp;
	p = wp = ken_data;
	do {
		p++;
		wp->next = p;
		wp = p;
	} while (p->code != DATA_END);
	// 目的：青森県のnextメンバの値を宮城県のアドレスに変更
	//　ポインタpにken_dataの先頭アドレスを代入
	p = ken_data;
	//　ポインタpを使って青森県のアドレスを求める
	p++;
	//　青森県のp->nextに宮城県のアドレス(pを使う）を代入
	p->next = p + 2;
	for (p = ken_data; p->code != DATA_END; p = p->next) {
		printf("code=%d name=%s\n", p->code, p->name);
	}
}