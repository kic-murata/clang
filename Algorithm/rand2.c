#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
	int dice, i;
	srand(time(0));
	for (i = 0; i < 3; i++) {
		dice = (rand() % 6) + 1;//1 ` 6 ‚Ü‚Å
		printf("ƒTƒCƒRƒ‚Ì–Ú‚Í%d‚Å‚·\n", dice);
	}
}