#include<stdio.h>
main()
{
	char moji[20];
	int cnt;
	printf("•¶š—ñ‚ÍH");
	scanf("%s", &moji[0]);
	cnt = 0;
	while (moji[cnt] != '\0') {
		cnt++;
	}
	printf("•¶š—ñF%s  •¶š”:%d•¶š\n", moji, cnt);
	cnt = 0;
	while (1) {
		if (moji[cnt] == '\0') break;
		cnt++;
	}
	printf("•¶š—ñF%s  •¶š”:%d•¶š\n", moji, cnt);
}