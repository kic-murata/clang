#include<stdio.h>
void strplus(char* s1, char* s2);
main()
{
	char a[256], b[256];
	printf("•¶š—ñ1H");
	gets(a);
	printf("•¶š—ñ2H");
	gets(b);
	strplus(a, b);
	printf("a:%s\n", a);
}
void strplus(char* s1, char* s2) {
	int i, j;
	for (i = 0; *(s1 + i) != '\0'; i++);
	printf("•¶š”:%d\n", i);
	for (j = 0; *(s2+j) !=  '\0'; j++) {
		*(s1 + i + j) = *(s2 + j);
	}
	*(s1 + i + j) = '\0';
}