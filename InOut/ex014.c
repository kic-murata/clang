#include<stdio.h>
main()
{
	//整数型変数noの宣言
	int no;
	//整数の入力を促す表示
	printf("整数を入れて：");
	//キーボードから整数を入力して変数noへ代入
	scanf("%d", &no);
	//変数noを10進整数(%d)で表示
	printf("入力値は%dです\n", no);
}