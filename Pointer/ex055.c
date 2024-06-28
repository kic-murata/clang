#include<stdio.h>
main()
{
	int a[] = { 11,22,33,44,55,66 };
	float b[] = { 11.1,22.2,33.3,44.4 };
	int* p_a = a;
	float* p_b = b;
	int i, a_sum = 0;
	float b_sum = 0;
	printf("sizeof:%d\n", (sizeof a / sizeof(int)));
	for (i = 0; i < (sizeof a/sizeof(int)); i++) {
		a_sum += *p_a;
		p_a++;
	}
	printf("配列a　合計=%d\t\t平均=%.3f\n", a_sum, (float)a_sum / (sizeof a / sizeof(int)));
	for (i = 0; i < (sizeof b/sizeof(float)); i++) {
		b_sum += *p_b;
		p_b++;
	}
	printf("配列b　合計=%.3f\t平均=%.3f\n", b_sum, b_sum / (sizeof b / sizeof(float)));
}