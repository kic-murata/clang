#include<stdio.h>
main()
{
	char data[15] = "C Language";
	char data2[15];
	char* p_data, * p_data2;
	p_data = data;
	p_data2 = data2;
	// printf("data[]=%s\n", data);	//�����^�z����w�肵�ĕ\��
	printf("data[]=%s\n", p_data);//������̃A�h���X���w�肵�ĕ\��
	while (*p_data2++ = *p_data++);
	/*while (*p_data != '\0') {
		*p_data2++ = *p_data++;
	}
	*p_data2 = '\0';*/

	p_data2 = data2;
	printf("data2[]=%s\n", p_data2);
	while (*p_data2) {
		putchar(*p_data2++);
	}
	putchar('\n');
}