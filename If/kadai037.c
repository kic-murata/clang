#include<stdio.h>
main()
{
	int n;
	printf("0�`100�܂ł̐����H");
	scanf("%d", &n);
	if (n < 30) {
		printf("���茋�ʁu1�v�ł�\n");
	}
	else {
		if (n < 50) {
			printf("���茋�ʂ́u2�v�ł�\n");
		}
		else {
			if (n < 80) {
				printf("���茋�ʂ́u3�v�ł�\n");
			}
			else {
				if (n < 90) {
					printf("���茋�ʂ́u4�v�ł�\n");
				}
				else {
					printf("���茋�ʂ́u5�v�ł�\n");
				}
			}
		}
	}

}