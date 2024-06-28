#include<stdio.h>
#define DATA_END -1
struct ken {
	int code;
	char name[20];
	struct ken* next;
};
main()
{
	struct ken ken_data[] = { {1,"北海道",NULL},{2,"青森県",NULL},{3,"岩手県",NULL},
		{4,"宮城県",NULL},{5,"秋田県",NULL},{6,"山形県",NULL},{7,"福島県",NULL},
		{DATA_END,"",NULL},{28,"兵庫県",NULL} };
	struct ken* p, * wp;
	p = wp = ken_data;
	do {
		p++;
		wp->next = p;
		wp = p;
	} while (p->code != DATA_END);
	// 目的：青森県のnextメンバの値を宮城県のアドレスに変更
	//　①ポインタpにken_dataの先頭アドレスを代入
	p = ken_data;
	//　②ポインタpを使って青森県のアドレスを求める
	p++;
	//　③青森県のp->nextに宮城県のアドレス(pを使う）を代入
	p->next = p + 2;
	// 目的：北海道のnextメンバの値を兵庫県のアドレスに変更して
	// 　　　兵庫県のnextメンバの値を青森県のアドレスにする
	// ①ポインタpにken_dataの先頭アドレス（北海道）を代入
	p = ken_data;
	// ②北海道のp->nextに兵庫県のアドレスを代入
	p->next = p + 8;
	// ③兵庫県のp->nextに青森県のアドレスを代入
	(p + 8)->next = p + 1;
	(p + 6)->next = p;
	for (p = ken_data; p->code != DATA_END; p = p->next) {
		printf("code=%d name=%s\n", p->code, p->name);
	}
}