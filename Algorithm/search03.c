#include<stdio.h>
main()
{
	int d[] = { 10,15,18,23,28,35,47,55,68,78,96 };
	int s, low, mid, high;
	printf("探索値を入力＞");
	scanf("%d", &s);
	low = 0;		//lowの初期値を設定
	high = 10;	//highの初期値を設定
	while (low <= high) {			//探索の継続条件
		mid = (low + high) / 2;	//添え字の中間値を求める
		//printf("low:%d mid:%d high:%d\n", low, mid, high);
		if (s == d[mid]) {			//sとデータの中間値が等しい
			break;								//ループ処理を抜ける
		}
		if (s > d[mid]) {				//sのほうがデータの中間値より大きい
			low = mid + 1;				//探索範囲の更新
		}
		if (s < d[mid]) {				//sのほうがデータの中間値より小さい
			high = mid - 1;				//探索範囲の更新
		}
	}
	if (low > high) {
		printf("見つかりませんでした\n");
		//printf("low:%d mid:%d high:%d\n", low, mid, high);
	}
	else {
		printf("d[%d]で%dを発見\n", mid, s);
	}
}