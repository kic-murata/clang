#include<stdio.h>
main()
{
	// �����^�ϐ�i�Ɨv�f��5�̔z��data��錾
	int i, data[5];
	// i��0�`4�ɕω��i�z��̓Y�����p�j
	for (i = 0; i < 5; i++) {
		// ���͂𑣂�
		printf("�z��data[%d]=", i);
		// �z��data�̓Y������ύX���ē���
		scanf("%d", &data[i]);
	}
	for (i = 0; i < 5; i++) {
		// �Y������0�`4�܂ŕύX���Ȃ���\��
		printf("data[%d]=%d\n", i, data[i]);
	}
}