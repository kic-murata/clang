#include<stdio.h>

main()
{
	int flg, d1, d2;
	printf("���Z�q����́F");
	scanf("%d", &flg);
	printf("2�̐�������́F");
	scanf("%d %d", &d1, &d2);
	if (flg == 1) {
		printf("%d\n", d1 + d2);
	}
	else {
		if (flg == 2) {
			printf("%d\n", d1 - d2);
		}
		else {
			if (flg == 3) {
				printf("%d\n", d1 * d2);
			}
			else {
				if (flg == 4) {
					printf("%d\n", d1 / d2);
				}
			}
		}
	}
}