#include<stdio.h>
struct profile {
	char name[20];
	int birth[3];
	char blood[5];
};
void disp(struct profile data);
main()
{
	struct profile data;
	printf("���O����́F");
	gets(data.name);
	printf("���N�������󔒂ŋ�؂��ē��́F");
	scanf("%d%d%d", &data.birth[0], &data.birth[1], &data.birth[2]);
	printf("���t�^����́F");
	scanf("%s", data.blood);
	disp(data);
}
void disp(struct profile data) {
	printf("%s - %d�N%d��%d�����@���t�^ - %s�^\n",
		data.name,
		data.birth[0], data.birth[1], data.birth[2],
		data.blood);
}