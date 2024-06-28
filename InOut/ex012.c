#include<stdio.h>
main()
{
	/*①文字型変数 moji の宣言*/
	char moji;
	/*②変数 moji に「A」を代入*/
	moji = 'a';
	/*③変数 moji に何か処理をして画面に「a」を表示*/
	printf("小文字に変換：%c\n", moji-32);
}