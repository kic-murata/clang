#include<stdio.h>
main()
{
	int m;				//整数型変数 m の宣言
	printf("月を入力（1〜12で入力）：");	//入力を促す表示
	scanf("%d", &m);	//キーボードから整数を入力して m へ格納
	if (m == 2) {		//m が 2と等しいとき
		printf("最終日は28日\n");
	}
	else {	//m が2と等しくないとき
		if (m == 4 || m == 6 || m == 9 || m == 11) { //mは4,6,9,11のいずれかと等しい？
			printf("最終日は30日\n");
		}	
		else {	//上記の条件とすべて合致しないとき（mが1,3,5,7,8,10,12のとき）
			printf("最終日は31日\n");
		}
	}
}