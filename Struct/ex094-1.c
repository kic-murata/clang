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
	struct profile data[NIN] = { {"A��",2000,2,11,"A"},
		{"B��",1999,12,31,"O"},	{"C��",1999,2,25,"AB"},
		{"D��",2000, 3, 1,"A"},	{"E��",1999,5,10,"B"} };
	struct profile* p;
	p = data;
	int i, j, k;
	char l[5];
	printf("���Ō������܂����H(1:���܂�N 2:���܂ꌎ 3:���t�^):");
	scanf("%d", &j);
	if (j == 1) {
		printf("���܂�N����́�");
		scanf("%d", &k);
	}
	if (j == 2) {
		printf("���܂ꌎ����́�");
		scanf("%d", &k);
	}
	if (j == 3) {
		printf("���t�^����́�");
		scanf("%s", l);
	}
	for (i = 0; i < NIN; i++) {
		if(j == 1){
			if ((p + i)->date.nen == k) {
				printf("%s -- %d�N%d��%d�����܂� ���t�^ - %s�^\n",
					(p + i)->name, (p + i)->date.nen, (p + i)->date.tuki,
					(p + i)->date.hi, (p + i)->blood);
			}
		}
		if(j == 2){
			if ((p + i)->date.tuki == k) {
				printf("%s -- %d�N%d��%d�����܂� ���t�^ - %s�^\n",
					(p + i)->name, (p + i)->date.nen, (p + i)->date.tuki,
					(p + i)->date.hi, (p + i)->blood);
			}
		}
		if (j == 3) {
			if (strcmp((p + i)->blood,l) == 0) {
				printf("%s -- %d�N%d��%d�����܂� ���t�^ - %s�^\n",
					(p + i)->name, (p + i)->date.nen, (p + i)->date.tuki,
					(p + i)->date.hi, (p + i)->blood);
			}
		}
	}
}