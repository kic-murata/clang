#include <stdio.h>
main()
{
	int a[3], * p;
	//int b = 1, c=b++;
	//int d = 1, e=++d;
	//printf("��u b=c++; b:%d c:%d\n", b, c);
	//printf("�O�u d=++e; d:%d e:%d\n", d, e);
	p = a;
	a[0] = 10, a[1] = 20, a[2] = 30;
	printf("*p    �E�E�E%d\n", *p);
	p = a;
	a[0] = 10, a[1] = 20, a[2] = 30;
	printf("*p+1  �E�E�E%d\n", *p + 1);
	p = a;
	a[0] = 10, a[1] = 20, a[2] = 30;
	printf("*(p+1)�E�E�E%d\n", *(p + 1));
	p = a;
	a[0] = 10, a[1] = 20, a[2] = 30;
	printf("*p+=1 �E�E�E%d\n", *p += 1);
	p = a;
	a[0] = 10, a[1] = 20, a[2] = 30;
	printf("------\n");
	printf("*p++  �E�E�E%d\n", *p++);
	printf("*p    �E�E�E%d\n", *p);
	p = a;
	a[0] = 10, a[1] = 20, a[2] = 30;
	printf("------\n");
	printf("(*p)++�E�E�E%d\n", (*p)++);
	printf("*p    �E�E�E%d\n", *p);
	printf("------\n");
		p = a;
	a[0] = 10, a[1] = 20, a[2] = 30;
	printf("*++p  �E�E�E%d\n", *++p);
	p = a;
	a[0] = 10, a[1] = 20, a[2] = 30;
	printf("++*p  �E�E�E%d\n", ++ * p);
}