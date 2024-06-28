#include<stdio.h>
#include<stdlib.h>
#include<time.h> //
#define Skil_Num 3
#define Mob_Num 3
//��������������UINT�ōĒ�`
typedef unsigned int UINT;

typedef struct { //Skill�^�\����
	char name[20]; //�X�L����
	int type;      //�X�L���̎�ށi0: HP��, 1: AtkUp, 2: ��Ԉُ�񕜁j
	int use_mp;    //�g�pMP��
	int effect;    //�X�L������
} Skill;
typedef struct { //Spec�^�\����
	char name[20]; //���O
	int hp;        //HP
	int atk;       //�U����
	int def;       //�h���
	UINT state;    //���
} Spec;
typedef struct { //Chara�^�\����
	Spec sp;       //Spec�^�\���̕ϐ�
	int maxhp;     //�ő�HP
	int mp;        //SP
	Skill skl[Skil_Num]; //Skill�^�\���̔z��
} Chara;
typedef struct { //Mob�^�\����
	Spec sp;       //Spec�^�\���̕ϐ�
	int rate;      //��Ԉُ�U���������[�g%�\�L
} Mob;

//�񋓌^BitState�̐錾
enum BitState
{
	//�ʏ���
	Base = 0,            //0000 0000 0000 0000
	//(1���炢�����ɃV�t�g���邩)
	Poison = 1 << 0,     //0000 0000 0000 0001(�ǂ�)
	Sleep = 1 << 1,      //0000 0000 0000 0010(�˂ނ�)
	Paralysis = 1 << 2,  //0000 0000 0000 0100(�܂�)
	Burn = 1 << 3,       //0000 0000 0000 1000(�₯��)
	AtkUp = 1 << 4,      //0000 0000 0001 0000(�U����Up)
	AtkDown = 1 << 5,    //0000 0000 0010 0000(�U����Down)
	Dead = 1 << 6        //0000 0000 0100 0000(���S�t���O)
};

int TurnCount = 0;       //�o�߃^�[��(0�`999)

//��Ԃ�ύX����֐�
void ChangeFlag(UINT *s);
//��Ԃ��񕜂���֐�
void ClearFlag(UINT *s);
//��Ԃ�\������֐�
void DisplayStatus(Chara c);

//�퓬���̃��j���[�\�����s��
int DisplayMenu(void);
//�X�L���g�p���̃��j���[�\�����s��
int SkillMenu(Chara c);
//�퓬���[�h�ֈڍs����֐�
void BattleMode(Chara* c, Mob m);
//�U�����Ɩh�䑤�̃p�����[�^���g�����U���_���[�W�v�Z
int DamageCalc(Spec sp1, Spec sp2);
//�퓬���[�h����HP�v�Z�Ǝ��S����
void BattleMessage(Spec sp1, Spec* sp2);

/* b_prac01.exe [����:0~Mob_Num-1]
* [����:0~Mob_Num-1]��0����Mob_Num-1�܂ł̐������w�肵�Ď��s���邱�Ƃ�
* �o�ꂷ��G�̎�ނ��w��ł���B�ȗ������ꍇ��0~Mob_Num-1�̗����ƂȂ� */
main(int argc,char *argv[])
{
	//������i�V�[�h�j�̏�����
	srand(time(0));
	//���L�����ƓG�L�����̃p�����[�^�ݒ�
	//���������ځF�f�[�^�t�@�C������̓ǂݍ���
	//              name    hp    atk  def  state maxhp mp
	Chara chara = { "��l��",2000, 200, 100, Base, 2000, 150, 
    //  sk.name    type usemp effect 
	   {{"HP��",     0,   50,  800},
		  {"AtkUp",     1,   50,  115},
		  {"��Ԉُ��",2,   20,    0}} };
	Mob mob[3] = { 
		//name hp   atk def  state   rate%
		{"�GA", 700,150, 800,Poison,  50},
		{"�GB",1500,200, 200,Burn,    50},
		{"�{�X",5000,200, 80,AtkDown, 10} };

	//������0~Mob_Num-1�̐��l�����߂�
	int num = rand() % Mob_Num;
	//���s���ɃR�}���h���C���������������ꍇ
	if (argc > 1) {
		//�����𐔒l�ɕϊ�
		num = atoi(argv[1]);
		//�����̐��l��0~Mob_Num-1�͈̔͂ɂȂ����
		if (num < 0 || num >= Mob_Num) {
			//�����𐶐�
			num = rand() % Mob_Num;
		}
	} 
	//�퓬���[�h���J�n
	BattleMode(&chara, mob[num]);
	if (chara.sp.state & Dead) {
		printf("%s�̎��S�ɂ��Q�[���I�[�o�[\n", chara.sp.name);
	}
}
/*int DamageCalc(Spec sp1, Spec sp2)
* �^�_���v�Z�֐�
* ��1�����FSpec�^�\���̕ϐ��i�U�����j
* ��2�����FSpec�^�\���̕ϐ��i�h�䑤�j
* �i�^�_���j���U����Atk*(�U����Atk���h�䑤Def�j�{�U����Atk*����0~0.5
* ���������ځF��S�̈ꌂ�i�ʏ��1.5�{�_���j
*/
int DamageCalc(Spec sp1, Spec sp2) {
	return sp1.atk * ((float)sp1.atk / sp2.def) + sp1.atk * (rand() % 50) / 100.0;
}
/*void BattleMessage(Spec sp1, Spec* sp2)
* �퓬���[�h���̃��b�Z�[�W�\�����s��
* ��1�����FSpec�^�\���̕ϐ��i�U�����j
* ��2�����FSpec�^�\���̕ϐ��̃A�h���X�i�h�䑤�j
*/
void BattleMessage(Spec sp1, Spec* sp2) {
	int damage;
	TurnCount++;
	printf("%s�̍U��\n", sp1.name);
	damage = DamageCalc(sp1, *sp2);
	printf("%s��%d�̃_���[�W\n\n", sp2->name,damage);
	sp2->hp -= damage;
	if (sp2->hp <= 0) {
		printf("%s�͓|���ꂽ\n", sp2->name);
		sp2->state |= Dead;
	}
}
/*void BattleMode(Chara* c, Mob m)
* �퓬���[�h���̃��b�Z�[�W�\�����s��
* ��1�����FChara�^�\���̕ϐ��̃A�h���X�i���L�����j
* ��2�����FMob�^�\���̕ϐ��i�G�L�����j*/
void BattleMode(Chara* c, Mob m) {
	int command, skill;
	system("cls");
	DisplayStatus(*c);
	printf("%s�������ꂽ�I\n", m.sp.name);
	while (1) {
		command = DisplayMenu();
		if (c->sp.state & Poison) {
			c->sp.hp *= 0.8;
		}
		if (c->sp.state & AtkDown) {
			c->sp.atk *= 0.95;
		}
		if (c->sp.state & Burn) {
			c->sp.hp *= 0.9;
			c->mp *= 0.9;
		}


		if (command == 1) {
			DisplayStatus(*c);
			if (TurnCount % 2 == 0) {
				BattleMessage(c->sp, &m.sp);

				if (m.sp.state & Dead) {
					break;
				}
			}
			if (TurnCount % 2 == 1) {
				BattleMessage(m.sp, &c->sp);
				if (rand() % 100 < m.rate) {
					printf("��Ԉُ�U�����󂯂��I\n");
					c->sp.state |= m.sp.state;
				}

				if (c->sp.state & Dead) {
					break;
				}
				else {
					DisplayStatus(*c);
				}
			}
		}
		else if (command == 2) {
			printf("�X�L���̑I��\n");
			skill = SkillMenu(*c);
			//MP�c�ʃ`�F�b�N
			if (c->mp >= c->skl[skill].use_mp) {
				switch (skill) {
				case 0:
					//HP����
					c->sp.hp += c->skl[skill].effect;
					//�񕜗ʂ�MAXHP�𒴂��Ȃ��悤��
					if (c->sp.hp > c->maxhp) { c->sp.hp = c->maxhp; }
					//MP�����炷
					c->mp -= c->skl[skill].use_mp;
					printf("HP��%d�񕜂���!\n", c->skl[skill].effect);
					DisplayStatus(*c);
					break;
				case 1:
					//ATK��1.15�{
					c->sp.atk *= c->skl[skill].effect / 100.0;
					//MP�����炷
					c->mp -= c->skl[skill].use_mp;
					printf("�U���͂��A�b�v����!\n");
					break;
				default:
					break;
				}
			}
			else {
				printf("MP������Ȃ��I\n");
			}

		}
		//�����I�����[�h�I�����̏���
		else if (command == -1) {
			c->sp.state |= Dead;
			break;
		}
	}
}
/*int DisplayMenu(void)
* �퓬���[�h���̃R�}���h�I����ʂ�\��
* �߂�l�F�I�������R�}���h�̃��j���[�ԍ� */
int DisplayMenu(void) {
	char ch;
	while (1) {
		printf("----------\n�R�}���h��I��\n");
		printf("1.��������\n2.�X�L��\n3.�ڂ�����\n\n");
		ch = getch();
		if (ch > '0' && ch < '4') {
			return ch - '0';
		}
		else if (ch == 'q') { //�B���R�}���h�F�����I��'q'
			return -1;
		}
	}
}
/*int SkillMenu(Chara c)
* �퓬���[�h���̃X�L���I����ʂ�\��
* ��1�����FChara�^�\���̕ϐ��i���L�����j
* �߂�l�F�I�������R�}���h�̃��j���[�ԍ� */
int SkillMenu(Chara c) {
	char ch;
	int i;
	while (1) {
		printf("----------\n�X�L����I��\n");
		for (i = 0; i < Skil_Num; i++) {
			printf("%d.%s\n", i + 1, c.skl[i].name);
		}
		printf("\n");
		ch = getch();
		if (ch > '0' && ch < '4') {
			return ch - '0' - 1;
		}
	}
}

/*void DisplayStatus(Chara c)
* �퓬���[�h���̎��L�����̃X�e�[�^�X�\��
* ��1�����FChara�^�\���̕ϐ��i���L�����j*/
void DisplayStatus(Chara c) {
	printf("******************\n");
	//HP��MP�\��
	printf("HP:%-4d  MP:%-3d\n",c.sp.hp, c.mp);
	//�t���O�������Ă���r�b�g�̊m�F
	if (c.sp.state) {
		printf("��ԁF ");
		if (c.sp.state & Poison) { printf("�� "); }
		if (c.sp.state & Sleep)  { printf("���� "); }
		if (c.sp.state & Paralysis) { printf("��� "); }
		if (c.sp.state & Burn)   { printf("�Ώ� "); }
		if (c.sp.state & AtkUp)  { printf("�U���̓A�b�v "); }
		if (c.sp.state & AtkDown){ printf("�U���̓_�E��"); }
	}
	printf("\n******************\n");
}
void ChangeFlag(UINT* s) {
	int a;
	while (1) {
		printf("�ǂ̏�Ԃɂ��܂����H\n");
		printf("1:�� 2:���� 3:��� 4:�Ώ� 5:�U���� 6:�U���� 0:���͏I����");
		scanf("%d",&a);
		if (a == 0) {
			break;
		}
		switch (a) {
			case 1: *s |= Poison; break;
			case 2: *s |= Sleep;  break;
			case 3: *s |= Paralysis; break;
			case 4: *s |= Burn;   break;
			case 5:	*s |= AtkUp;  break;
			case 6: *s |= AtkDown;break;
		}
	}
}
void ClearFlag(UINT* s) {
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