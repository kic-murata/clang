#include<stdio.h>
main()
{
	// �����^�ϐ� i�̐錾��1�ւ̏�����
	int i = 1;
	// do~while�̌J��Ԃ�����
	do {
		//i=�H�̕\���i�H�̕����͕ϐ�i�̒l�j
		printf("i=%d\n", i);
		//�ϐ�i�̃C���N�������g
		i++;
	  //�㔻�菈���ii��10�ȉ��̂Ƃ��J��Ԃ��j
	} while (i <= 10);
}