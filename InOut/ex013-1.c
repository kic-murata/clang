#include<stdio.h>
main()
{
	/*文字型変数 go と　ro を宣言*/
	char go, ro;
	/*変数 go に'5'を代入*/
	go = '5';
	/*変数 ro に'6'を代入*/
	ro = '6';
	/*5×6の結果をgoとroの演算を使って%dで表示*/
	printf("5x6=%d\n", (go-48) * (ro-48));
}