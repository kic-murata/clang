#include<stdio.h>
main()
{
	int a, i = 0, sum = 0;
	printf("�����F");
	while (scanf("%d", &a) != EOF) {
		sum += a;	 //sum=sum+a;�ł���
		i++;
		printf("�����F");
	}
	printf("���v��%d ����=%.2f\n", sum, (float)sum/i);
}