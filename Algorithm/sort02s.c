#include<stdio.h>
#define N 5
main()
{
	int d[N] = { 30,7,25,16,10 };
	int i, j, w;
	int min=0, max=N-1;
	printf("ソート前：");
	for (i = 0; i < N; i++) {
		printf("%d ", d[i]);
	}
	printf("\n");

	// d[0]～d[4] 左から右
	for (j = min; j < max; j++) {
			if (d[j] > d[j + 1]) {
				w = d[j];
				d[j] = d[j + 1];
				d[j + 1] = w;
			}
	}
	max--;
	// d[3]～d[0] 右から左
	for (j = max; j > min; j--) {
			if (d[j] < d[j - 1]) {
				w = d[j];
				d[j] = d[j - 1];
				d[j - 1] = w;
			}
	}
	min++;
	// d[1]～d[3] 左から右
	for (j = min; j < max; j++) {
			if (d[j] > d[j + 1]) {
				w = d[j];
				d[j] = d[j + 1];
				d[j + 1] = w;
			}
	}
	max--;
	// d[2]～d[1] 右から左
	for (j = max; j > min; j--) {
			if (d[j] < d[j - 1]) {
				w = d[j];
				d[j] = d[j - 1];
				d[j - 1] = w;
			}
	}
	printf("\nソート後：");
	for (i = 0; i < N; i++) {
		printf("%d ", d[i]);
	}
}