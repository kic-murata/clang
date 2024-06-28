#include<stdio.h>
main()
{
	//実数型変数fnoを宣言
	float fno;
	//「実数を入れて：」と画面表示
	printf("実数を入れて：");
	//キーボードから実数値を入力してfnoへ代入
	scanf("%f", &fno );
	//fnoを2倍した値と3倍した値を表示
	printf("2倍すると%f\n3倍すると%f\n", fno*2 , fno*3 );
}
