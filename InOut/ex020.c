#include<stdio.h>
main()
{
	//文字型変数mojiの宣言
	char moji;
	//「小文字を入力：」と画面表示
	print("小文字を入力：");
	//キーボードから英小文字を入力して変数mojiに格納
	scanf("%c", &moji);
	//「大文字に変換して」＋変数mojiを処理して大文字にして表示
	printf("大文字に変換して %c\n",moji-32);
}