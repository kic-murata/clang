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
		printf("\n\n���G���L���[��i�A�f�L���[��o����́i�I����e�j��");
		key = getche();
		printf("\n");

		if (key == 'i') {
			printf("�f�[�^���́�");
			scanf("%d", &data);
			result = enqueue(data);
			if (result == -1) {
				printf("\n�������L���[����t�ł�������\n");
			}
			else {
				display();
			}
		}
		if (key == 'o') {
			result = dequeue(&data);
			if (result == -1) {
				printf("\n�������L���[����ł�������\n");
			}
			else {
				printf("�L���[����f�[�^(%d)�����o����\n", data);
				display();
			}
		}
	} while (key != 'e');
}
void display(void) {
	int i;
	printf("\n���������݂̃L���[�̓��e������\n");
	for (i = 0; i < QUEUESIZE; i++) {
		printf("queue[%2d]��%5d", i, queue[i]);
		if (i == head) {
			printf(" �� head�������Ă���ꏊ�i����head��%d�j", head);
		}
		if (i == tail) {
			printf(" �� tail�������Ă���ꏊ�i����tail��%d�j", tail);
		}
		printf("\n");
	}
	return;
}
int enqueue(int d) {
	if ((tail + 1) % QUEUESIZE == head) { return -1; }
	queue[tail] = d;	//�����ŗ^����ꂽ�f�[�^d��z��queue��tail�̏ꏊ�Ɋi�[
	tail++;						//tail���ЂƂi�߂�
	tail = tail % QUEUESIZE;	//tail���z��̖����𒴂����Ƃ��̏���
	/*
	if(tail > QUEUESIZE-1) { tail = 0; }
	*/
	return 0;
}
int dequeue(int* pd) {
	if (tail == head) { return -1; }
	*pd = queue[head];//�z��queue��head�̈ʒu�̃f�[�^�����o���ă|�C���^�ϐ��֊i�[
	queue[head] = 0;	//�f�[�^���f�L���[�����Ƃ����0����
	head++;						//head���ЂƂi�߂�
	head = head % QUEUESIZE; //head���z��̖����𒴂����Ƃ��̏���
	return 0;
}