#include<stdio.h>
main()
{
	char str[200];
	printf("���������́F");
	while (gets(str) != NULL) {
		printf("%s\n", str);
		//gets(str);
		printf("���������́F");
	}
}