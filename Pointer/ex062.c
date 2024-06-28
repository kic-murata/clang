#include<stdio.h>
main()
{
	char* p = "peach";
	char data1[10] = "banana", * p_data1;
	char data2[10], * p_data2;
	p_data1 = data1;
	p_data2 = data2;
	while (*p_data2++ = *p_data1++);
	p_data1 = data1;
	while (*p_data1++ = *p++);
	p_data1 = data1;
	p_data2 = data2;
	printf("data1[]=%s\n", p_data1 );
	printf("data2[]=%s\n", p_data2 );
}