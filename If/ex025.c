#include<stdio.h>
main()
{
	char ch;
	printf("文字を入力：");
	scanf("%c", &ch);
	if ((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')) {
		printf("アルファベット\n");
	}
	else {
		if (ch >= '0' && ch <= '9') {
			printf("数字\n");
		}
		else {
			printf("その他の文字\n");
		}
	}
}