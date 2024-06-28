/* ----------------------------------------------------------------------- */
/* ファイル名：sort05.c */
/* 　概　要　：ソートの実行速度を比較することでアルゴリズムの大事さを */
/* 　　　　　　理解する。（※関数化はせずmain関数のみで作成） */
/* 作　成　日：2019/05/15 */
/* 最終更新日：2020/05/25 */
/* 作　成　者：穐原弘樹 */
/* ----------------------------------------------------------------------- */
/* ヘッダファイル -------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* 記号定数 -------------------------------------------------------------- */
#define SIZE 50000 // テスト用データ数
/* main関数　エントリポイント -------------------------------------------- */
int main(void)
{
	int dat1[SIZE]; // ソートテスト用配列１
	int dat2[SIZE]; // ソートテスト用配列２
	int i, j, gap, w;
	clock_t t1_start, t1_end, t2_start, t2_end;
	// テストデータを作成（２つの配列に同じテストデータを設定する）
	srand((unsigned)time(NULL)); // 乱数系列の初期化
	for (i = 0; i < SIZE; i++) {
		w = rand(); // 乱数を取得（0～RAND_MAX）
		if (rand() % 2) {
			// 取得した乱数をそのまま設定
			dat1[i] = w;
			dat2[i] = w;
		}
		else {
			// 取得した乱数をマイナスに変換して設定
			dat1[i] = -w;
			dat2[i] = -w;
		}
	}
	// 基本選択法による昇順ソート（教科書P155～P156）
	t1_start = clock(); // 選択ソート開始時間取得
	for (i = 0; i < SIZE - 1; i++) {
		for (j = i + 1; j < SIZE; j++) {
			if (dat1[i] > dat1[j]) {
				w = dat1[i];
				dat1[i] = dat1[j];
				dat1[j] = w;
			}
		}
	}
	t1_end = clock(); // 選択ソート終了時間取得
	// シェルソートによる昇順ソート（教科書P161～P164）
	t2_start = clock(); // シェルソート開始時間取得
	gap = SIZE / 2;
	while (gap > 0) {
		for (i = gap; i < SIZE; i++) {
			for (j = i - gap; j >= 0; j -= gap) {
				if (dat2[j + gap] < dat2[j]) {
					w = dat2[j];
					dat2[j] = dat2[j + gap];
					dat2[j + gap] = w;
				}
				else {
					break;
				}
			}
		}
		gap = gap / 2;
	}
	t2_end = clock(); // シェルソート終了時間取得
	// 正しく昇順に整列済みかチェック
	for (i = 0; i < SIZE - 1; i++) {
		if (dat1[i] > dat1[i + 1] ||
			dat1[i] != dat2[i] ||
			dat1[i + 1] != dat2[i + 1]) {
			printf("エラー：ソートに失敗しています\n");
			exit(1);
		}
	}
	// 結果の表示
	printf("選択ソート処理時間　：%dミリ秒\n\n", t1_end - t1_start);
	printf("シェルソート処理時間：%dミリ秒\n\n", t2_end - t2_start);
	printf("実行速度を「%.2f」倍に改善しました。\n",
		(double)(t1_end - t1_start) / (t2_end - t2_start));
	return 0;
}