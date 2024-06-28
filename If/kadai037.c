#include<stdio.h>
main()
{
	int n;
	printf("0～100までの整数？");
	scanf("%d", &n);
	if (n < 30) {
		printf("判定結果「1」です\n");
	}
	else {
		if (n < 50) {
			printf("判定結果は「2」です\n");
		}
		else {
			if (n < 80) {
				printf("判定結果は「3」です\n");
			}
			else {
				if (n < 90) {
					printf("判定結果は「4」です\n");
				}
				else {
					printf("判定結果は「5」です\n");
				}
			}
		}
	}

}