#include<stdio.h>
#include<string.h>
#define NIN 5
struct profile {
	char name[20]; int birth[3]; char blood[5];
};
main()
{
	struct profile data[NIN];
	struct profile* p;
	p = data;	// �udata[i].�v���u(p+i)->�v�ɏ�������
	int i;
	for (i = 0; i < NIN; i++) {
		printf("%d�l�ځi���O�j�F", i + 1);
		scanf("%s", (p + i)->name);
		printf("%d�l�ځi���N�����j�F", i + 1);
		scanf("%d%d%d", &(p + i)->birth[0],&(p + i)->birth[1], &(p + i)->birth[2]);
		printf("%d�l�ځi���t�^�j�F", i + 1);
		scanf("%s", (p + i)->blood);
	}
	for (i = 0; i < NIN; i++) {
		if (strcmp((p + i)->blood, "A") == 0) {
			printf("%s -- %d�N%d��%d�����܂� ���t�^ - %s�^\n",
				(p + i)->name, (p + i)->birth[0], (p + i)->birth[1],
				(p + i)->birth[2], (p + i)->blood);
		}
	}
}