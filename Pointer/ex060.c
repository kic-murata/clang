#include<stdio.h>
main()
{
	char data[] = "Language";
	char* p_data, ch;
	int i = 0, j = 0;
	p_data = data;
	printf("data[]=%s\n", p_data);
	printf("���������́H");
	scanf("%c", &ch);
	printf("�������ʂ́A");
	while (*(p_data + i)) {				// *(p_data+i) <= *p_data
		if (ch == *(p_data + i)) {  // *(p_data+i) <= *p_data++
			printf("%d ", i + 1);
			j++;
		}
		i++;
	}
	if (j > 0) {
		printf("�����ڂł�\n");
	}
	else {
		printf("������܂���\n");
	}
}