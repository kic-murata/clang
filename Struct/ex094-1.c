#include<stdio.h>
#include<string.h>
#define NIN 5
struct day {
	int nen;
	int tuki;
	int hi;
};
struct profile {
	char name[20];
	struct day date;
	char blood[5];
};
main()
{
	struct profile data[NIN] = { {"A氏",2000,2,11,"A"},
		{"B氏",1999,12,31,"O"},	{"C氏",1999,2,25,"AB"},
		{"D氏",2000, 3, 1,"A"},	{"E氏",1999,5,10,"B"} };
	struct profile* p;
	p = data;
	int i, j, k;
	char l[5];
	printf("何で検索しますか？(1:生まれ年 2:生まれ月 3:血液型):");
	scanf("%d", &j);
	if (j == 1) {
		printf("生まれ年を入力＞");
		scanf("%d", &k);
	}
	if (j == 2) {
		printf("生まれ月を入力＞");
		scanf("%d", &k);
	}
	if (j == 3) {
		printf("血液型を入力＞");
		scanf("%s", l);
	}
	for (i = 0; i < NIN; i++) {
		if(j == 1){
			if ((p + i)->date.nen == k) {
				printf("%s -- %d年%d月%d日生まれ 血液型 - %s型\n",
					(p + i)->name, (p + i)->date.nen, (p + i)->date.tuki,
					(p + i)->date.hi, (p + i)->blood);
			}
		}
		if(j == 2){
			if ((p + i)->date.tuki == k) {
				printf("%s -- %d年%d月%d日生まれ 血液型 - %s型\n",
					(p + i)->name, (p + i)->date.nen, (p + i)->date.tuki,
					(p + i)->date.hi, (p + i)->blood);
			}
		}
		if (j == 3) {
			if (strcmp((p + i)->blood,l) == 0) {
				printf("%s -- %d年%d月%d日生まれ 血液型 - %s型\n",
					(p + i)->name, (p + i)->date.nen, (p + i)->date.tuki,
					(p + i)->date.hi, (p + i)->blood);
			}
		}
	}
}