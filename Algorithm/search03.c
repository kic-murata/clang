#include<stdio.h>
main()
{
	int d[] = { 10,15,18,23,28,35,47,55,68,78,96 };
	int s, low, mid, high;
	printf("�T���l����́�");
	scanf("%d", &s);
	low = 0;		//low�̏����l��ݒ�
	high = 10;	//high�̏����l��ݒ�
	while (low <= high) {			//�T���̌p������
		mid = (low + high) / 2;	//�Y�����̒��Ԓl�����߂�
		//printf("low:%d mid:%d high:%d\n", low, mid, high);
		if (s == d[mid]) {			//s�ƃf�[�^�̒��Ԓl��������
			break;								//���[�v�����𔲂���
		}
		if (s > d[mid]) {				//s�̂ق����f�[�^�̒��Ԓl���傫��
			low = mid + 1;				//�T���͈͂̍X�V
		}
		if (s < d[mid]) {				//s�̂ق����f�[�^�̒��Ԓl��菬����
			high = mid - 1;				//�T���͈͂̍X�V
		}
	}
	if (low > high) {
		printf("������܂���ł���\n");
		//printf("low:%d mid:%d high:%d\n", low, mid, high);
	}
	else {
		printf("d[%d]��%d�𔭌�\n", mid, s);
	}
}