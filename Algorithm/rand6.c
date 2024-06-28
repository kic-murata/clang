#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
	int pl, cpu;
	printf("何を出しますか？\n");
	printf("(1:グー 2:チョキ 3:パー)＞");
	scanf("%d", &pl);
	if (pl == 1) {
		printf("プレイヤーはグーです\n");
	}
	if (pl == 2) {
		printf("プレイヤーはチョキです\n");
	}
	if (pl == 3) {
		printf("プレイヤーはパーです\n");
	}
	/* switch文で書いてもよい
	switch (pl) {
	case 1: ・・・・
	}
	*/
	srand(time(0));
	cpu = rand() % 3;
	if (cpu == 0) {
		printf("コンピュータはグーです\n");
	}
	if (cpu == 1) {
		printf("コンピュータはチョキです\n");
	}
	if (cpu == 2) {
		printf("コンピュータはパーです\n");
	}
	// プレイヤー勝ちパターン
	if ((pl-cpu+3)%3==0) {
		printf("プレイヤーの勝ちです\n");
	}
	// プレイヤー負けパターン
	if ((pl - cpu + 3) % 3 == 2) {
		printf("プレイヤーの負けです\n");
	}
	// あいこパターン
	if ((pl - cpu + 3) % 3 == 1) {
		printf("あいこです\n");
	}
}