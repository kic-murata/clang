#include<stdio.h>
enum BitState {
	Base = 0,						//00000000　通常
	Poison = 1 << 0,		//00000001　どく
	Sleep = 1 << 1,			//00000010　ねむり
	Paralysis = 1 << 2,	//00000100	まひ
	Burn = 1 << 3,			//00001000	やけど
	AtkUp = 1 << 4,			//00010000　攻撃力アップ
	AtkDown = 1 << 5		//00100000　攻撃力ダウン
};
typedef unsigned int UINT;
void DisplayStatus(UINT s);
void ChangeFlag(UINT* s);
void ClearFlag(UINT* s);
main()
{
	//状態を管理する変数MyStateを宣言してBase(0)で初期化
	UINT MyState = Base;
	ChangeFlag(&MyState);
	//DisplayStatus(MyState);
	ClearFlag(&MyState);
	//DisplayStatus(MyState);
}
void DisplayStatus(UINT s) {
	printf("*****現在の状態*****\n");
	if (s & Poison) {
		printf("毒\n");
	}
	if (s & Sleep) {
		printf("睡眠\n");
	}
	if (s & Paralysis) {
		printf("麻痺\n");
	}
	if (s & Burn) {
		printf("火傷\n");
	}
	if (s & AtkUp) {
		printf("攻撃力アップ\n");
	}
	if (s & AtkDown) {
		printf("攻撃力ダウン\n");
	}
	printf("********************\n");
}
void ChangeFlag(UINT* s) {
	int a;
	while (1) {
		DisplayStatus(*s);
		printf("どの状態にしますか？\n");
		printf("1:毒 2:睡眠 3:麻痺 4:火傷 5:攻撃↑ 6:攻撃↓ 0:入力終了>");
		scanf("%d", &a);
		if (a == 0) {
			break;
		}
		switch (a) {
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
		default:
			break;
		}
	}
}
void ClearFlag(UINT* s) {
	int a;
	while (1) {
		DisplayStatus(*s);
		printf("どの状態を回復しますか\n");
		printf("1:毒 2:睡眠 3:麻痺 4:火傷 5:攻撃↑ 6:攻撃↓ 7:状態クリア　0:入力終了>");
		scanf("%d", &a);
		if (a == 0) {
			break;
		}
		switch (a) {
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
		case 7:  //すべての状態を解除（全ビットを落とす）＝初期状態にする
			*s = Base;
			break;
		default:
			break;
		}
	}
}