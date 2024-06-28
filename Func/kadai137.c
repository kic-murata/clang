#include<stdio.h>
int hikaku(char a);
main()
{
	char a;
	printf("アルファベット１文字？");
	scanf("%c", &a);
	if (hikaku(a) == 0) {
		printf("小文字\n");
	}
	else {
		printf("大文字\n");
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