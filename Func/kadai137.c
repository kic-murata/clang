#include<stdio.h>
int hikaku(char a);
main()
{
	char a;
	printf("�A���t�@�x�b�g�P�����H");
	scanf("%c", &a);
	if (hikaku(a) == 0) {
		printf("������\n");
	}
	else {
		printf("�啶��\n");
	}
}
int hikaku(char a) {
	if (a >= 0x61 && a <= 0x7a) {
		return(0);
	}
	else {
		return(1);
	}
}