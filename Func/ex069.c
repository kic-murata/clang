#include<stdio.h>
main()
{
	int a, i = 0, sum = 0;
	printf("®”F");
	while (scanf("%d", &a) != EOF) {
		sum += a;	 //sum=sum+a;‚Å‚à‰Â
		i++;
		printf("®”F");
	}
	printf("‡Œv%d •½‹Ï=%.2f\n", sum, (float)sum/i);
}