#include<stdio.h>
void swap(int* a, int* b);
main()
{
	int a, b;
	printf("�������Q���́F");
	scanf("%d%d", &a, &b);
	printf("�֐����s�O�̒l�F\na=%d\tb=%d\n", a, b);
	swap(&a, &b); //�֐������s
	printf("�֐����s��̒l�F\na=%d\tb=%d\n", a, b);
}
void swap(int* a, int* b) {
	int w;
	w = *a;
	*a = *b;
	*b = w;
}