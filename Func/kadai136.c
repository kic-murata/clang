#include<stdio.h>
int hikaku(int a, int b);
main()
{
	int a, b;
	printf("‚Q‚Â‚Ì®”H");
	scanf("%d%d", &a, &b);
	printf("max=%d\n", hikaku(a, b));
}
int hikaku(int a, int b) {
	if (a >= b) {
		return(a);
	}
	else {
		return(b);
	}
}