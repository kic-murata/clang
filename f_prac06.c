#include<stdio.h>
//マップデータの数
#define MapNum 3
//マップデータの横の最大マス
#define W 10
//マップデータの縦の最大マス
#define H 5
//マップデータ管理用構造体
typedef struct {
	int m_map[H][W];	//2次元配列
} Map;
typedef struct {
	int x, y;
} Pos;
//マップデータ読み込み関数
void SetMap(char* filename, Map* m);
//マップデータ表示関数
void DrawMap(Map m);
void CharaMove(Map* m,Pos* p);
main()
{
	//Map型構造体の変数MapDataを宣言
	Map MapData;
	Pos CharaPos = { 1,1 };
	//マップデータファイル名
	char* MapFileName[MapNum] =
	{ "map0.txt","map1.txt","map2.txt" };
	//マップデータを選択する際のデータ番号保存用
	int select = 0;
	//データ番号が規定値におさまっているかの確認
	if (select >= 0 && select <= 2) {
		//指定のデータ番号のマップデータを読み出す
		SetMap(MapFileName[select], &MapData);
		MapData.m_map[CharaPos.y][CharaPos.x] = 2;
		while (1) {
			system("cls");
			//読みだしたマップデータを表示する
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

//第一引数がマップデータのファイル名、第二引数がマップデータ保存用の構造体
void SetMap(char* filename, Map* m) {
	//ファイルポインタの宣言
	FILE* fp;
	//マップデータ読み出し用の文字型変数
	char ch;
	//ループ処理用変数の宣言
	int i, j;
	//ファイルを読み取りモードで開く
	if (fp = fopen(filename, "r")) {
		//2次元配列格納用にH×Wの二重ループを実行
		for (i = 0; i < H; i++) {
			for (j = 0; j < W; j++) {
				//指定のファイルから一文字読み出し
				ch = fgetc(fp);
				//読み出した文字を配列要素に整数として格納
				m->m_map[i][j] = ch - '0';
			}
			//行末の\nを読み捨てる
			fgetc(fp);
		}
		//ファイルを閉じる
		fclose(fp);
	}
}
//第一引数はマップデータが格納された構造体変数
void DrawMap(Map m) {
	//ループ処理用変数
	int i, j;
	//2次元配列から値を取り出すためのH×Wの二重ループを実行
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			//2次元配列の各要素の値をチェックして処理を振り分ける
			switch (m.m_map[i][j]) {
			case 0:
				//０のときは空白表示
				printf(" ");
				break;
			case 1:
				//１のときは■を表示
				printf("■");
				break;
			case 2:
				//２のときは@を表示
				printf("@");
				break;
			case 3:
				printf("$");
				break;
			}
		}
		//行末で改行
		printf("\n");
	}
}