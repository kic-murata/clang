#include<stdio.h>
main()
{
	int num, i;
	printf("��������");
	scanf("%d", &num);
	i = 0;
	while (i <= 10) {
		printf("%d+%d=%d\n",num,i,num+i);
		i++;
	}
}