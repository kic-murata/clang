#include<stdio.h>
main()
{
	int a = 100, b = 200, w;
	int* p_a = &a, * p_b = &b;
	printf("���s�O�Fa=%d\tb=%d\n", a, b);
	w = *p_a;			// w:100  *p_a:100
	*p_a = *p_b;	// *p_a:200 *p_b:200
								//*p_b = w;			// b = w�@�Ɠ���
	p_b = &w;			// p_b��w�̃A�h���X������
								// *p_b:100  w:100
	printf("���s��Fa=%d\tb=%d\n", a, b);
	printf("&a=%d\t&b=%d\t&w=%d\n", &a, &b, &w);
	printf("p_a=%d\tp_b=%d\n", p_a, p_b);
	printf("&p_a=%d\t&p_b=%d\n", &p_a, &p_b);
}