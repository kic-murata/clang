#include<stdio.h>
#define QUEUESIZE 2
int queue[QUEUESIZE];
int head = 0;
int tail = 0;

void display(void);
int enqueue(int d);
int dequeue(int* pd);

main()
{
	int key, data, result;
	do {
		printf("\n\n◆エンキューはi、デキューはoを入力（終了はe）＞");
		key = getche();
		printf("\n");

		if (key == 'i') {
			printf("データ入力＞");
			scanf("%d", &data);
			result = enqueue(data);
			if (result == -1) {
				printf("\n※※※キューが一杯です※※※\n");
			}
			else {
				display();
			}
		}
		if (key == 'o') {
			result = dequeue(&data);
			if (result == -1) {
				printf("\n※※※キューが空です※※※\n");
			}
			else {
				printf("キューからデータ(%d)を取り出した\n", data);
				display();
			}
		}
	} while (key != 'e');
}
void display(void) {
	int i;
	printf("\n＝＝＝現在のキューの内容＝＝＝\n");
	for (i = 0; i < QUEUESIZE; i++) {
		printf("queue[%2d]は%5d", i, queue[i]);
		if (i == head) {
			printf(" ← headが示している場所（現在headは%d）", head);
		}
		if (i == tail) {
			printf(" ← tailが示している場所（現在tailは%d）", tail);
		}
		printf("\n");
	}
	return;
}
int enqueue(int d) {
	if ((tail + 1) % QUEUESIZE == head) { return -1; }
	queue[tail] = d;	//引数で与えられたデータdを配列queueのtailの場所に格納
	tail++;						//tailをひとつ進める
	tail = tail % QUEUESIZE;	//tailが配列の末尾を超えたときの処理
	/*
	if(tail > QUEUESIZE-1) { tail = 0; }
	*/
	return 0;
}
int dequeue(int* pd) {
	if (tail == head) { return -1; }
	*pd = queue[head];//配列queueのheadの位置のデータを取り出してポインタ変数へ格納
	queue[head] = 0;	//データをデキューしたところに0を代入
	head++;						//headをひとつ進める
	head = head % QUEUESIZE; //headが配列の末尾を超えたときの処理
	return 0;
}