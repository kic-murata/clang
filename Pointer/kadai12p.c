#include<stdio.h>
#define WEEK 7
main()
{
	char* day[] = { "Sunday","Monday","Tuesday","Wednesday",
								"Thursday","Friday","Saturday",NULL };
	char** p = day;
	int i;
	//パターン�@　day[i]の形式で文字列を表示
	for (i = 0; i < WEEK; i++) {
		printf("%s\n", day[i]);
	}
	//パターン�A-1　*pを用いて文字列を表示
	for (i = 0; i < WEEK; i++) {
		printf("%s\n", *(p + i));
	}
	//パターン�A-2
	while (*p) {
		printf("%s\n", *p++);
	}
}