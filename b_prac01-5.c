#include<stdio.h>
#include<stdlib.h>
#include<time.h>
enum BitState {
	Base = 0,						//00000000�@�ʏ�
	Poison = 1 << 0,		//00000001�@�ǂ�
	Sleep = 1 << 1,			//00000010�@�˂ނ�
	Paralysis = 1 << 2,	//00000100	�܂�
	Burn = 1 << 3,			//00001000	�₯��
	AtkUp = 1 << 4,			//00010000�@�U���̓A�b�v
	AtkDown = 1 << 5		//00100000�@�U���̓_�E��
};
typedef unsigned int UINT;
typedef struct {
	char name[20];
	int hp;
	int mp;
	int atk;
	int def;
	UINT MyState;
} Chara;
typedef struct {
	char name[20];
	int hp;
	int atk;
	int def;
	UINT state;
} Mob;

void DisplayStatus(UINT s);
void ChangeFlag(UINT* s);
void ClearFlag(UINT* s);
int DisplayMenu(void);
main()
{
	//               name   hp   mp  atk def MyState
	Chara chara = { "��l��",2000,200,100,50,Base };
	//               name hp atk def state
	Mob mob[3] = { {"�GA",100,50,20,Base},
		             {"�GB",1000,100,40,Base},
		             {"�GC",5000,500,100,Base}};
	srand(time(0));
}
int DisplayMenu(void) {
	char ch;
	printf("�R�}���h�H\n");
	printf("1:��������\n2:�ڂ�����\n");
	ch = getch();
}

void DisplayStatus(UINT s) {
	printf("*****���݂̏��*****\n");
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
	printf("********************\n");
}
void ChangeFlag(UINT* s) {
	int a;
	while (1) {
		DisplayStatus(*s);
		printf("�ǂ̏�Ԃɂ��܂����H\n");
		printf("1:�� 2:���� 3:��� 4:�Ώ� 5:�U���� 6:�U���� 0:���͏I��>");
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
		printf("�ǂ̏�Ԃ��񕜂��܂���\n");
		printf("1:�� 2:���� 3:��� 4:�Ώ� 5:�U���� 6:�U���� 7:��ԃN���A�@0:���͏I��>");
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
		case 7:  //���ׂĂ̏�Ԃ������i�S�r�b�g�𗎂Ƃ��j��������Ԃɂ���
			*s = Base;
			break;
		default:
			break;
		}
	}
}