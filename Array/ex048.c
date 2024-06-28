#include<stdio.h>
main()
{
	int a[2][2][3] = { {{3,4,5},{4,5,6}}
					  ,{{2,2,3},{2,5,6}} };
	int i, j, k, sum;
	for (sum = 0, k = 0; k < 2; k++) {
		for (j = 0; j < 2; j++) {
			for (i = 0; i < 3; i++) {
				sum += a[k][j][i];
			}
		}
	}
	printf("‡Œv%d\n", sum);
	
}