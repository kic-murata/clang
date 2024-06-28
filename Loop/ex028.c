#include<stdio.h>
main()
{
	int gokei, ia;			//整数型変数gokei,iaの宣言
	gokei = 0;				//変数gokeiを0にリセット
	ia = 0;
	//printf("数を入れて");		//入力を促す表示
	//scanf("%d", &ia);		//変数iaにキーボード入力
	while (ia != -999) {	//iaが-999でなければループ
		gokei += ia;		//変数gokeiにiaを足し合わせる
		printf("数を入れて");	//入力を促す
		scanf("%d", &ia);	//変数iaにキーボード入力
	}						//ループ終了
	printf("合計=%d\n", gokei);	//合計値の表示
}