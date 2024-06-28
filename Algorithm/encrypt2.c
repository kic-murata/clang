#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
	int i = 0, n, k[21],d;
	char s[21];
	scanf("%d", &d);
	srand(d);		//乱数シードの初期化
	printf("文字列を入力してください＞");
	scanf("%s", &s[0]);
	while (s[i] != '\0') {
		k[i] = rand() % 6;	// 0～5の乱数生成
		s[i] = s[i] + k[i];	// s[i] += k[i];
		i++;								// 文字をひとつ進める
	}
	printf("i=%d\n", i);
	printf("暗号化文字列は%s\n", s);
	printf("暗号化キーは、");
	for (n = 0; n < i; n++) {
		printf("%d", k[n]);
	}
}