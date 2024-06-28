#include<stdio.h>
#include<stdlib.h>
#define MapNum 3
#define W 10
#define H 5
typedef struct {
	int m_map[H][W];
} Map;
typedef struct{
	int x,y;
} Pos;
int IsClear = 0;

void SetMap(char* filename, Map* m);
void DrawMap(Map m);
void CharaMove(Map* m, Pos* p);
void CheckMove(Map* m, Pos p2, Pos* p);
main()
{
	Map MapData;
	//自キャラの初期位置を構造体のメンバに初期化で与える
	Pos CharaPos = { 1, 1 };
	char* MapFileName[MapNum] =
	{ "map0.txt","map1.txt","map2.txt" };
	int select;
	printf("表示マップ？（0,1,2)＞");
	scanf("%d", &select);
	if (select >= 0 && select <= 2) {
		SetMap(MapFileName[select], &MapData);
		//自キャラの初期位置をマップデータに書き込む
		MapData.m_map[CharaPos.x][CharaPos.y] = 2;
		while (1) {
			//画面消去
			system("cls");
			DrawMap(MapData);
			CharaMove(&MapData, &CharaPos);
			//クリアフラグが-1になったら強制終了
			if (IsClear == -1) {
				printf("\nGiveUp！\n");
				break;
			}
			else if (IsClear == 1) {
				system("cls");
				DrawMap(MapData);
				printf("\nゴール！\n");
				break;
			}
		}
	}
}
void SetMap(char* filename, Map* m) {
	FILE* fp;
	char ch;
	int i, j;
	if (fp = fopen(filename, "r")) {
		for (i = 0; i < H; i++) {
			for (j = 0; j < W; j++) {
				ch = fgetc(fp);
				m->m_map[i][j] = ch - '0';
			}
			fgetc(fp);
		}
		fclose(fp);
	}
}
void DrawMap(Map m) {
	int i, j;
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			switch (m.m_map[i][j]) {
			case 0:
				printf(" ");
				break;
			case 1:
				printf("■");
				break;
			case 2:
				printf("@");
				break;
			case 3:
				printf("$");
				break;
			}
		}
		printf("\n");
	}
}
void CharaMove(Map* m, Pos* p) {
	char ch;
	ch = getch();
	Pos p2 = *p;
	switch (ch) {
	case 'w':
		p2.y -= 1;
		break;
	case 's':
		p2.y += 1;
		break;
	case 'a':
		p2.x -= 1;
		break;
	case 'd':
		p2.x += 1;
		break;
	case '0':
		IsClear = -1;
		break;
	default:
		break;
	}
	CheckMove(m, p2, p);
}
void CheckMove(Map* m, Pos p2, Pos* p) {
	int cm = m->m_map[p2.y][p2.x];
	switch (cm) {
	case 3:
		IsClear = 1;
		break;
	case 2:
		return;
		break;
	case 1:
		return;
		break;
	}
	//if (cm != 1) {
	//	if (cm == 3) {
	//		IsClear = 1;
	//	}
	//	else if (cm == 2) {
	//		return;
	//	}
		m->m_map[p2.y][p2.x] = 2;
		m->m_map[p->y][p->x] = 0;
		*p = p2;
	//}
}