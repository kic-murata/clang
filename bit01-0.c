#include<stdio.h>
//��������������UINT�ōĒ�`
typedef unsigned int UINT;

//�񋓌^BitState�̐錾
enum BitState
{
	//�ʏ���
	Base = 0,		//0000 0000 0000 0000
	//(1���炢�����ɃV�t�g���邩)
	Poison = 1 << 0,	//0000 0000 0000 0001(�ǂ�)
	Sleep = 1 << 1,	//0000 0000 0000 0010(�˂ނ�)
	Paralysis = 1 << 2,	//0000 0000 0000 0100(�܂�)
	Burn = 1 << 3,	//0000 0000 0000 1000(�₯��)
	AtkUp = 1 << 4,	//0000 0000 0001 0000(�U����Up)
	AtkDown = 1 << 5	//0000 0000 0010 0000(�U����Down)
};

//��Ԃ�ύX����֐�
void ChangeStatus(UINT *s);
//��Ԃ��񕜂���֐�
void ClearStatus(UINT *s);
//��Ԃ�\������֐�
void DisplayStatus(UINT s);

main()
{
	//��Ԃ��Ǘ�����ϐ�Status��錾
	UINT Status = Base;		//0000 0000

	ChangeStatus(&Status);
	DisplayStatus(Status);
	ClearStatus(&Status);
	DisplayStatus(Status);
}

void DisplayStatus(UINT s) {
	//�t���O�������Ă���r�b�g�̊m�F
	printf("****���݂̏��****\n");
	if (s & Poison)
	{
		printf("�ǂ�\n");
	}
	if (s & Sleep)
	{
		printf("�˂ނ�\n");
	}
	if (s & Paralysis)
	{
		printf("�܂�\n");
	}
	if (s & Burn)
	{
		printf("�₯��\n");
	}
	if (s & AtkUp)
	{
		printf("�U���̓A�b�v\n");
	}
	if (s & AtkDown)
	{
		printf("�U���̓_�E��\n");
	}
	printf("******************\n");
}
void ChangeStatus(UINT* s) {
	int ch;
	while (1) {
		printf("�ǂ̏�Ԃɂ��܂����H\n");
		printf("1:�� 2:���� 3:��� 4:�Ώ� 5:�U���� 6:�U���� 0:���͏I����");
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
		printf("�ǂ̏�Ԃ��񕜂��܂����H\n");
		printf("1:�� 2:���� 3:��� 4:�Ώ� 5:�U���� 6:�U���� 0:���͏I����");
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