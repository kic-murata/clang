#include<stdio.h>
main()
{
	float fn1, fn2, fn3;
	printf("1�߂̎����F");
	scanf("%f", &fn1);
	printf("2�߂̎����F");
	scanf("%f", &fn2);
	printf("3�߂̎����F");
	scanf("%f", &fn3);
	printf("���v��%f ����=%f\n", fn1+fn2+fn3, (fn1+fn2+fn3)/3 );
}