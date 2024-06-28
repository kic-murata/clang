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
//�}�b�v�f�[�^�ǂݍ��݊֐�
void SetMap(char* filename, Map* m);
//�}�b�v�f�[�^�\���֐�
void DrawMap(Map m);
main()
{
	//Map�^�\���̂̕ϐ�MapData��錾
	Map MapData;
	//�}�b�v�f�[�^�t�@�C����
	char* MapFileName[MapNum] =
	{ "map0.txt","map1.txt","map2.txt" };
	//�}�b�v�f�[�^��I������ۂ̃f�[�^�ԍ��ۑ��p
	int select;
	//�ǂ̃}�b�v�f�[�^��\�����邩��I��������
	printf("�\���}�b�v�H�i0,1,2)��");
	scanf("%d", &select);
	//�f�[�^�ԍ����K��l�ɂ����܂��Ă��邩�̊m�F
	if (select >= 0 && select <= 2) {
		//�w��̃f�[�^�ԍ��̃}�b�v�f�[�^��ǂݏo��
		SetMap(MapFileName[select], &MapData);
		//�ǂ݂������}�b�v�f�[�^��\������
		DrawMap(MapData);
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