#include<stdio.h>
#define N 5
main()
{
	int d[N] = { 30,7,25,16,10 };
	int i, j, w;
	int min=0, max=N-1;
	printf("�\�[�g�O�F");
	for (i = 0; i < N; i++) {
		printf("%d ", d[i]);
	}
	printf("\n");

	// d[0]�`d[4] ������E
	for (j = min; j < max; j++) {
			if (d[j] > d[j + 1]) {
				w = d[j];
				d[j] = d[j + 1];
				d[j + 1] = w;
			}
	}
	max--;
	// d[3]�`d[0] �E���獶
	for (j = max; j > min; j--) {
			if (d[j] < d[j - 1]) {
				w = d[j];
				d[j] = d[j - 1];
				d[j - 1] = w;
			}
	}
	min++;
	// d[1]�`d[3] ������E
	for (j = min; j < max; j++) {
			if (d[j] > d[j + 1]) {
				w = d[j];
				d[j] = d[j + 1];
				d[j + 1] = w;
			}
	}
	max--;
	// d[2]�`d[1] �E���獶
	for (j = max; j > min; j--) {
			if (d[j] < d[j - 1]) {
				w = d[j];
				d[j] = d[j - 1];
				d[j - 1] = w;
			}
	}
	printf("\n�\�[�g��F");
	for (i = 0; i < N; i++) {
		printf("%d ", d[i]);
	}
}