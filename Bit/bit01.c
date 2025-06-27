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
	printf("****���݂̏��****\n");
	if (s & Poison) {
		printf("��\n");
	}
	if (s & Sleep) {
		printf("����\n");
	}
	if (s & Paralysis) {
		printf("���\n");
	}
	if (s & Burn) {
		printf("�Ώ�\n");
	}
	if (s & AtkUp) {
		printf("�U���̓A�b�v\n");
	}
	if (s & AtkDown) {
		printf("�U���̓_�E��\n");
	}
	if (s == Base) {
		printf("��ԕω��Ȃ�\n");
	}
	printf("******************\n");
}
void ChangeFlag(UINT* s) {
	int a;
	while (1) {
		DisplayStatus(*s);
		printf("�ǂ̏�Ԃ�t�^���܂����H\n");
		printf("%d:�� %d:���� %d:��� %d:�Ώ� %d:�U���� %d:�U����  %d:�S�N���A>"
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
		//default:	//1~6�ȊO�̒l�̂Ƃ�
		//	break;
		//}
	}
}
void ClearFlag(UINT* s) {
	int a;
	while (1) {
		DisplayStatus(*s);
		printf("�ǂ̏�Ԃ��������܂����H\n");
		printf("1:�� 2:���� 3:��� 4:�Ώ� 5:�U���� 6:�U���� 7:�S���� 0:�I��>");
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