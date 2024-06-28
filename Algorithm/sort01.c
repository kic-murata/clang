#include<stdio.h>
#define N 5
main()
{
	int d[N] = { 30,7,25,16,10 };
	int i, j, w;
	printf("ソート前：");
	for (i = 0; i < N; i++) {
		printf("%d ", d[i]);
	}
	printf("\n");
	for (i = 0; i < N - 1; i++) {
		for (j = i + 1; j < N; j++) {
			if (d[i] > d[j]) {	// 昇順ソート（不等号が逆のときは降順）
				w = d[i];
				d[i] = d[j];
				d[j] = w;
			}
		}
	}
	printf("ソート後：");
	for (i = 0; i < N; i++) {
		printf("%d ", d[i]);
	}
}