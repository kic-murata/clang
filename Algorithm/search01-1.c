#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
	int i, s;
	int d[10];
	srand(time(0));
	for (i = 0; i < 10; i++) {
		d[i] = rand() % 30 + 1;
	}
	printf("�T���l�����:");
	scanf("%d", &s);
	for (i = 0; i < 10; i++) {
		//printf("i=%d\n", i);
		if (s == d[i]) {
			break;
		}
	}
	if (i == 10) {
		printf("���̓f�[�^%d�͌�����Ȃ�����\n",s);
	}
	else {
		printf("%d�ԖڂɌ�������\n", i);
	}
}