#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
	int i, un;
	srand(time(0));
	un = rand() % 5 + 1; // un=1`5
	printf("¡“ú‚Ì‚ ‚È‚½‚Ì‰^¨‚ÍA");
	for (i = 1 ; i <= un ; i++) {
		printf("™");
	}
	printf("‚Å‚·B\n");
}