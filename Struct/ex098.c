#include<stdio.h>
#define DATA_END -1
struct ken {
	int code;
	char name[20];
	struct ken* next;
};
main()
{
	struct ken ken_data[] = { {1,"�k�C��",NULL},{2,"�X��",NULL},{3,"��茧",NULL},
		{4,"�{�錧",NULL},{5,"�H�c��",NULL},{6,"�R�`��",NULL},{7,"������",NULL},
		{DATA_END,"",NULL},{28,"���Ɍ�",NULL} };
	struct ken* p, * wp;
	p = wp = ken_data;
	do {
		p++;
		wp->next = p;
		wp = p;
	} while (p->code != DATA_END);
	// �ړI�F�X����next�����o�̒l���{�錧�̃A�h���X�ɕύX
	//�@�@�|�C���^p��ken_data�̐擪�A�h���X����
	p = ken_data;
	//�@�A�|�C���^p���g���ĐX���̃A�h���X�����߂�
	p++;
	//�@�B�X����p->next�ɋ{�錧�̃A�h���X(p���g���j����
	p->next = p + 2;
	// �ړI�F�k�C����next�����o�̒l�𕺌Ɍ��̃A�h���X�ɕύX����
	// �@�@�@���Ɍ���next�����o�̒l��X���̃A�h���X�ɂ���
	// �@�|�C���^p��ken_data�̐擪�A�h���X�i�k�C���j����
	p = ken_data;
	// �A�k�C����p->next�ɕ��Ɍ��̃A�h���X����
	p->next = p + 8;
	// �B���Ɍ���p->next�ɐX���̃A�h���X����
	(p + 8)->next = p + 1;
	(p + 6)->next = p;
	for (p = ken_data; p->code != DATA_END; p = p->next) {
		printf("code=%d name=%s\n", p->code, p->name);
	}
}