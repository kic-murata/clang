#include<stdio.h>
void strplus(char* s1, char* s2);
main()
{
	char a[256], b[256];
	printf("文字列1？");
	gets(a);
	printf("文字列2？");
	gets(b);
	strplus(a, b);
	printf("a:%s\n", a);
}
void strplus(char* s1, char* s2) {
	int i, j;
	for (i = 0; *(s1 + i) != '\0'; i++);
	printf("文字数:%d\n", i);
	for (j = 0; *(s2+j) !=  '\0'; j++) {
		*(s1 + i + j) = *(s2 + j);
	}
	*(s1 + i + j) = '\0';
}