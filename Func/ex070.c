#include<stdio.h>
int add(int a, int b);
int hiku(int a, int b);
int kake(int a, int b);
int wari(int a, int b);
main()
{
	int a, b, kotae;
	printf("整数を２つ入力：");
	scanf("%d%d", &a, &b);
	printf("合計は %d です\n", add(a, b));
	printf("減算結果は %d です\n", hiku(a, b));
	printf("乗算結果は %d です\n", kake(a, b));
	printf("除算結果は %d です\n", wari(a, b));
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