#include<stdio.h>
#define WEEK 7
main()
{
	char* day[] = { "Sunday","Monday","Tuesday","Wednesday",
								"Thursday","Friday","Saturday",NULL };
	char** p = day;
	int i;
	//�p�^�[���@�@day[i]�̌`���ŕ������\��
	for (i = 0; i < WEEK; i++) {
		printf("%s\n", day[i]);
	}
	//�p�^�[���A-1�@*p��p���ĕ������\��
	for (i = 0; i < WEEK; i++) {
		printf("%s\n", *(p + i));
	}
	//�p�^�[���A-2
	while (*p) {
		printf("%s\n", *p++);
	}
}