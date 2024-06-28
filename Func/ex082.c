#include<stdio.h>
void sort(int* array, int size, int order);
main()
{
	int data[8] = { 6,10,8,2,9,5,1,7 };
	int i, order;
	printf("ソート方向を入力（0:降順／1:昇順）＞");
	scanf("%d", &order);
	sort(data, 8, order);
	for (i = 0; i < 8; i++) {
		printf("%d ", data[i]);
	}
}
void sort(int* array, int size, int order) {
	int i, j, w;
	if (order == 0) {	//降順ソート
		for (i = 0; i < size - 1;i++) {
			for (j = i + 1; j < size;j++) {
				if (*(array + i) < *(array + j)) {
					w = *(array + i);
					*(array + i) = *(array + j);
					*(array + j) = w;
				}
			}
		}
	}
	else {						//昇順ソート
		for (i = 0; i < size - 1; i++) {
			for (j = i + 1; j < size; j++) {
				if (*(array + i) > *(array + j)) {
					w = *(array + i);
					*(array + i) = *(array + j);
					*(array + j) = w;
				}
			}
		}
	}
}