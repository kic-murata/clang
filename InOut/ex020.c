#include<stdio.h>
main()
{
	//�����^�ϐ�moji�̐錾
	char moji;
	//�u����������́F�v�Ɖ�ʕ\��
	print("����������́F");
	//�L�[�{�[�h����p����������͂��ĕϐ�moji�Ɋi�[
	scanf("%c", &moji);
	//�u�啶���ɕϊ����āv�{�ϐ�moji���������đ啶���ɂ��ĕ\��
	printf("�啶���ɕϊ����� %c\n",moji-32);
}