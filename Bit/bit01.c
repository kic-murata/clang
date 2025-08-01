#include<stdio.h>

enum BitState
{
	Base = 0,          //00000000
	Poison = 1 << 0,   //00000001
	Sleep = 1 << 1,    //00000010
	Paralysis = 1 << 2,//00000100
	Burn = 1 << 3,     //00001000
	AtkUp = 1 << 4,    //00010000
	AtkDown = 1 << 5   //00100000
};
typedef unsigned int UINT;
void DisplayStatus(UINT);
void ChangeFlag(UINT*);
void ClearFlag(UINT*);
main() {
	UINT MyState = Base;
	ChangeFlag(&MyState);
	//DisplayStatus(MyState);
	ClearFlag(&MyState);
	//DisplayStatus(MyState);
}
void DisplayStatus(UINT s) {
	printf("****現在の状態****\n");
	if (s & Poison) {
		printf("毒\n");
	}
	if (s & Sleep) {
		printf("眠り\n");
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
	if (s == Base) {
		printf("状態変化なし\n");
	}
	printf("******************\n");
}
void ChangeFlag(UINT* s) {
	int a;
	while (1) {
		DisplayStatus(*s);
		printf("どの状態を付与しますか？\n");
		printf("%d:毒 %d:睡眠 %d:麻痺 %d:火傷 %d:攻撃↑ %d:攻撃↓  %d:全クリア>"
		,Poison, Sleep, Paralysis, Burn, AtkUp, AtkDown, Base);
		scanf("%d", &a);
		if (a == 0) {
			*s = Base;
		}
		else {
			*s |= a;
		}

		//switch (a) {
		//case Poison:
		//	*s |= Poison;
		//	break;
		//case Sleep:
		//	*s |= Sleep;
		//	break;
		//case Paralysis:
		//	*s |= Paralysis;
		//	break;
		//case Burn:
		//	*s |= Burn;
		//	break;
		//case AtkUp:
		//	*s |= AtkUp;
		//	break;
		//case AtkDown:
		//	*s |= AtkDown;
		//	break;
		//default:	//1~6以外の値のとき
		//	break;
		//}
	}
}
void ClearFlag(UINT* s) {
	int a;
	while (1) {
		DisplayStatus(*s);
		printf("どの状態を解除しますか？\n");
		printf("1:毒 2:睡眠 3:麻痺 4:火傷 5:攻撃↑ 6:攻撃↓ 7:全解除 0:終了>");
		scanf("%d", &a);
		if (a == 0) {
			break;
		}
		switch(a) {
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
		case 7:
			//*s &= ~(Poison | Sleep | Paralysis | Burn | AtkUp | AtkDown);
			*s = Base;
			break;
		default:
			break;
		}
	}
}