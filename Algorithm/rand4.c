#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
	int i, un;
	srand(time(0));
	un = rand() % 5 + 1; // un=1〜5
	printf("今日のあなたの運勢は、");
	for (i = 1 ; i <= un ; i++) {
		printf("☆");
	}
	printf("です。\n");
}