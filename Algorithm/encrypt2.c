#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
	int i = 0, n, k[21],d;
	char s[21];
	scanf("%d", &d);
	srand(d);		//�����V�[�h�̏�����
	printf("���������͂��Ă���������");
	scanf("%s", &s[0]);
	while (s[i] != '\0') {
		k[i] = rand() % 6;	// 0�`5�̗�������
		s[i] = s[i] + k[i];	// s[i] += k[i];
		i++;								// �������ЂƂi�߂�
	}
	printf("i=%d\n", i);
	printf("�Í����������%s\n", s);
	printf("�Í����L�[�́A");
	for (n = 0; n < i; n++) {
		printf("%d", k[n]);
	}
}