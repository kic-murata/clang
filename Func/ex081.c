#include<stdio.h>
int get_max(int* array, int size);
int get_min(int* array, int size);
main()
{
	int data[8] = { 6,10,8,2,9,5,1,7 };
	printf("�ő�l=%d\n", get_max(data, 8));
	printf("�ŏ��l=%d\n", get_min(data, 8));
}
int get_max(int* array, int size) {
	int max, i;
	max = *array;	//���̍ő�l�͔z��̐擪�v�f
	for (i = 1; i < size; i++) {
		if (max < *(array + i)) {
			max = *(array + i);
		}
	}
	return(max);
}
int get_min(int* array, int size) {
	int min, i;
	min = *array;	//���̍Œl�͔z��̐擪�v�f
	for (i = 1; i < size; i++) {
		if (min > *(array + i)) {
			min = *(array + i);
		}
	}
	return(min);
}