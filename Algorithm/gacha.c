#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
	int gacha,i;
	srand(time(0));
	for (i = 0; i < 10; i++) {
		gacha = rand() % 100 + 1;
		//printf("gacha=%d\n", gacha);
		if (gacha >= 50) {
			printf("š ƒm[ƒ}ƒ‹\n");
		}
		else {
			if (gacha >= 20) {
				printf("šš ƒŒƒA\n");
			}
			else {
				if (gacha >= 6) {
					printf("ššš SR\n");
				}
				else {
					if (gacha >= 2) {
						printf("šššš UR\n");
					}
					else {
						printf("ššššš LR\n");
					}
				}
			}
		}
	}
}