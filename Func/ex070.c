#include<stdio.h>
int add(int a, int b);
int hiku(int a, int b);
int kake(int a, int b);
int wari(int a, int b);
main()
{
	int a, b, kotae;
	printf("�������Q���́F");
	scanf("%d%d", &a, &b);
	printf("���v�� %d �ł�\n", add(a, b));
	printf("���Z���ʂ� %d �ł�\n", hiku(a, b));
	printf("��Z���ʂ� %d �ł�\n", kake(a, b));
	printf("���Z���ʂ� %d �ł�\n", wari(a, b));
}
int add(int a, int b) {
	return(a + b);
}
int hiku(int a, int b) {
	return(a - b);
}
int kake(int a, int b) {
	return(a * b);
}
int wari(int a, int b) {
	return(a / b);
}