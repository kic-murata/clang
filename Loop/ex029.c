#include<stdio.h>
main()
{
	int num, i;
	printf("��������");
	scanf("%d", &num);
	i = 0;
	while (i < num) {
		printf("*");
		i=i+1;
	}
}