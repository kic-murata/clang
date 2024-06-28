#include<stdio.h>
//符号無し整数をUINTで再定義
typedef unsigned int UINT;

//列挙型BitStateの宣言
enum BitState
{
	//通常状態
	Base = 0,		//0000 0000 0000 0000
	//(1からいくつ左にシフトするか)
	Poison = 1 << 0,	//0000 0000 0000 0001(どく)
	Sleep = 1 << 1,	//0000 0000 0000 0010(ねむり)
	Paralysis = 1 << 2,	//0000 0000 0000 0100(まひ)
	Burn = 1 << 3,	//0000 0000 0000 1000(やけど)
	AtkUp = 1 << 4,	//0000 0000 0001 0000(攻撃力Up)
	AtkDown = 1 << 5	//0000 0000 0010 0000(攻撃力Down)
};

//状態を変更する関数
void ChangeStatus(UINT *s);
//状態を回復する関数
void ClearStatus(UINT *s);
//状態を表示する関数
void DisplayStatus(UINT s);

main()
{
	//状態を管理する変数Statusを宣言
	UINT Status = Base;		//0000 0000

	ChangeStatus(&Status);
	DisplayStatus(Status);
	ClearStatus(&Status);
	DisplayStatus(Status);
}

void DisplayStatus(UINT s) {
	//フラグが立っているビットの確認
	printf("****現在の状態****\n");
	if (s & Poison)
	{
		printf("どく\n");
	}
	if (s & Sleep)
	{
		printf("ねむり\n");
	}
	if (s & Paralysis)
	{
		printf("まひ\n");
	}
	if (s & Burn)
	{
		printf("やけど\n");
	}
	if (s & AtkUp)
	{
		printf("攻撃力アップ\n");
	}
	if (s & AtkDown)
	{
		printf("攻撃力ダウン\n");
	}
	printf("******************\n");
}
void ChangeStatus(UINT* s) {
	int ch;
	while (1) {
		printf("どの状態にしますか？\n");
		printf("1:毒 2:睡眠 3:麻痺 4:火傷 5:攻撃↑ 6:攻撃↓ 0:入力終了＞");
		scanf("%d",&ch);
		switch (ch) {
		case 1:
			*s |= Poison;
			break;
		case 2:
			*s |= Sleep;
			break;
		case 3:
			*s |= Paralysis;
			break;
		case 4:
			*s |= Burn;
			break;
		case 5:
			*s |= AtkUp;
			break;
		case 6:
			*s |= AtkDown;
			break;
		}
		if (ch == 0) {
			break;
		}
	}
}
void ClearStatus(UINT* s) {
	int ch;
	while (1) {
		printf("どの状態を回復しますか？\n");
		printf("1:毒 2:睡眠 3:麻痺 4:火傷 5:攻撃↑ 6:攻撃↓ 0:入力終了＞");
		scanf("%d", &ch);
		switch (ch) {
		case 1:
			*s &= ~Poison;
			break;
		case 2:
			*s &= ~Sleep;
			break;
		case 3:
			*s &= ~Paralysis;
			break;
		case 4:
			*s &= ~Burn;
			break;
		case 5:
			*s &= ~AtkUp;
			break;
		case 6:
			*s &= ~AtkDown;
			break;
		}
		if (ch == 0) {
			break;
		}
	}
}