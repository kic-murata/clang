#include<stdio.h>
main()
{
	int num;
	printf("���������:");
	scanf("%d", &num);
	if (num >= 10 && num <= 49) {
		switch (num / 10) {
		case 1:
			printf("10�_��\n");
			break;
		case 2:
			printf("20�_��\n");
			break;
		case 3:
			printf("30�_��\n");
			break;
		case 4:
			printf("40�_��\n");
			break;
		}
	}
	else {
		printf("���̓G���[\n");
	}
}