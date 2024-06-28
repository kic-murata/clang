#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
	int k, atk; //k=1～100 atk=-5～+5
	int i= 1, hp = 200;
	srand(time(0));
	while (hp >= 0) {
		printf("ターン%d:", i++);
		k = rand() % 100 + 1;
		atk = 20 + (rand() % 11 - 5);
		if (k <= 30) {
			printf("かいしんの一撃!\n");
			printf("ダメージ：%d", 2 * atk);
			hp -= atk * 2;
		}
		else {
			printf("通常攻撃\n");
			printf("ダメージ：%d", atk);
			hp -= atk;
		}
		printf("(残りhp:%d)\n\n", hp);
	}
	printf("敵を倒した！\n");
}