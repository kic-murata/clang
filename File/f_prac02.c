#include<stdio.h>
main()
{
	int max_score, score = 0;
	char max_name[20], ch, name[20];
	FILE* fp;
	if (fp = fopen("score.txt", "r")) {
		fscanf(fp, "%s%d", max_name, &max_score);
		fclose(fp);
	}
	else {
		printf("ファイル読み込みエラー\n");
		return;
	}
	printf("最高得点 名前:%s スコア:%d\n",
								max_name, max_score);

	printf("プレイヤー名を入力:");
	scanf("%s", name);
	while (1) {
		printf("スコア:%d ('e'で終了)\n",
			score);
		ch = getch();
		if (ch == 'e') {
			break;
		}
		score++;
	}
	if (score > max_score) {
		if (fp = fopen("score.txt", "w")) {
			fprintf(fp, "%s\n%d\n",
				name, score);
			fclose(fp);
		}
	}
}