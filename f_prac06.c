#include<stdio.h>
//�}�b�v�f�[�^�̐�
#define MapNum 3
//�}�b�v�f�[�^�̉��̍ő�}�X
#define W 10
//�}�b�v�f�[�^�̏c�̍ő�}�X
#define H 5
//�}�b�v�f�[�^�Ǘ��p�\����
typedef struct {
	int m_map[H][W];	//2�����z��
} Map;
typedef struct {
	int x, y;
} Pos;
//�}�b�v�f�[�^�ǂݍ��݊֐�
void SetMap(char* filename, Map* m);
//�}�b�v�f�[�^�\���֐�
void DrawMap(Map m);
void CharaMove(Map* m,Pos* p);
main()
{
	//Map�^�\���̂̕ϐ�MapData��錾
	Map MapData;
	Pos CharaPos = { 1,1 };
	//�}�b�v�f�[�^�t�@�C����
	char* MapFileName[MapNum] =
	{ "map0.txt","map1.txt","map2.txt" };
	//�}�b�v�f�[�^��I������ۂ̃f�[�^�ԍ��ۑ��p
	int select = 0;
	//�f�[�^�ԍ����K��l�ɂ����܂��Ă��邩�̊m�F
	if (select >= 0 && select <= 2) {
		//�w��̃f�[�^�ԍ��̃}�b�v�f�[�^��ǂݏo��
		SetMap(MapFileName[select], &MapData);
		MapData.m_map[CharaPos.y][CharaPos.x] = 2;
		while (1) {
			system("cls");
			//�ǂ݂������}�b�v�f�[�^��\������
			DrawMap(MapData);
			CharaMove(&MapData, &CharaPos);
		}
	}
}
void CharaMove(Map* m, Pos* p) {
	char ch;
	ch = getch();
	switch (ch) {
	case 'd':
		if (m->m_map[p->y][(p->x) + 1] != 1) {
			m->m_map[p->y][p->x] = 0;
			m->m_map[p->y][(p->x) + 1] = 2;
			p->x += 1;
		}
		break;
	case 'a':
		if (m->m_map[p->y][(p->x) - 1] != 1) {
			m->m_map[p->y][p->x] = 0;
			m->m_map[p->y][(p->x) - 1] = 2;
			p->x -= 1;
		}
		break;
	case 'w':
		if (m->m_map[(p->y) - 1][(p->x)] != 1) {
			m->m_map[p->y][p->x] = 0;
			m->m_map[(p->y) - 1][(p->x)] = 2;
			p->y -= 1;

		}
		break;
	case 's':
		if (m->m_map[(p->y) + 1][(p->x)] != 1) {
			m->m_map[p->y][p->x] = 0;
			m->m_map[(p->y) + 1][(p->x)] = 2;
			p->y += 1;
		}
		break;
	}

}

//���������}�b�v�f�[�^�̃t�@�C�����A���������}�b�v�f�[�^�ۑ��p�̍\����
void SetMap(char* filename, Map* m) {
	//�t�@�C���|�C���^�̐錾
	FILE* fp;
	//�}�b�v�f�[�^�ǂݏo���p�̕����^�ϐ�
	char ch;
	//���[�v�����p�ϐ��̐錾
	int i, j;
	//�t�@�C����ǂݎ�胂�[�h�ŊJ��
	if (fp = fopen(filename, "r")) {
		//2�����z��i�[�p��H�~W�̓�d���[�v�����s
		for (i = 0; i < H; i++) {
			for (j = 0; j < W; j++) {
				//�w��̃t�@�C������ꕶ���ǂݏo��
				ch = fgetc(fp);
				//�ǂݏo����������z��v�f�ɐ����Ƃ��Ċi�[
				m->m_map[i][j] = ch - '0';
			}
			//�s����\n��ǂݎ̂Ă�
			fgetc(fp);
		}
		//�t�@�C�������
		fclose(fp);
	}
}
//�������̓}�b�v�f�[�^���i�[���ꂽ�\���̕ϐ�
void DrawMap(Map m) {
	//���[�v�����p�ϐ�
	int i, j;
	//2�����z�񂩂�l�����o�����߂�H�~W�̓�d���[�v�����s
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			//2�����z��̊e�v�f�̒l���`�F�b�N���ď�����U�蕪����
			switch (m.m_map[i][j]) {
			case 0:
				//�O�̂Ƃ��͋󔒕\��
				printf(" ");
				break;
			case 1:
				//�P�̂Ƃ��́���\��
				printf("��");
				break;
			case 2:
				//�Q�̂Ƃ���@��\��
				printf("@");
				break;
			case 3:
				printf("$");
				break;
			}
		}
		//�s���ŉ��s
		printf("\n");
	}
}