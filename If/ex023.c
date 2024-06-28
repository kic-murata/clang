#include<stdio.h>
main()
{
	int sec, h=0, m=0, s=0;
	printf("秒数を入力：");
	scanf("%d", &sec);
	if (sec <= 5000) {
		h = sec / 3600;
		m = (sec % 3600)/ 60;
		//s = ((sec % 3600) % 60);
		s = sec % 60;
		printf("%d時間%d分%d秒\n", h, m, s);
	}
	else {
		printf("エラー!!\n5000以内にしてください。\n");
	}
}