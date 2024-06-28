#include<stdio.h>
int add(int a, int b);
int hiku(int a, int b);
int kake(int a, int b);
int wari(int a, int b);
main()
{
	int a, b, kotae;
	printf("®”‚ğ‚Q‚Â“ü—ÍF");
	scanf("%d%d", &a, &b);
	printf("‡Œv‚Í %d ‚Å‚·\n", add(a, b));
	printf("Œ¸ZŒ‹‰Ê‚Í %d ‚Å‚·\n", hiku(a, b));
	printf("æZŒ‹‰Ê‚Í %d ‚Å‚·\n", kake(a, b));
	printf("œZŒ‹‰Ê‚Í %d ‚Å‚·\n", wari(a, b));
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