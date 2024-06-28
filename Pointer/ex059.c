#include<stdio.h>
main()
{
	char data[15] = "C Language";
	char data2[15];
	char* p_data, * p_data2;
	p_data = data;
	p_data2 = data2;
	// printf("data[]=%s\n", data);	//文字型配列を指定して表示
	printf("data[]=%s\n", p_data);//文字列のアドレスを指定して表示
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