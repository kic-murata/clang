#include<stdio.h>
main()
{
	int gokei, ia;			//�����^�ϐ�gokei,ia�̐錾
	gokei = 0;				//�ϐ�gokei��0�Ƀ��Z�b�g
	ia = 0;
	//printf("��������");		//���͂𑣂��\��
	//scanf("%d", &ia);		//�ϐ�ia�ɃL�[�{�[�h����
	while (ia != -999) {	//ia��-999�łȂ���΃��[�v
		gokei += ia;		//�ϐ�gokei��ia�𑫂����킹��
		printf("��������");	//���͂𑣂�
		scanf("%d", &ia);	//�ϐ�ia�ɃL�[�{�[�h����
	}						//���[�v�I��
	printf("���v=%d\n", gokei);	//���v�l�̕\��
}