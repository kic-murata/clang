#include <stdio.h>
main()
{
	int a[3], * p;
	//int b = 1, c=b++;
	//int d = 1, e=++d;
	//printf("後置 b=c++; b:%d c:%d\n", b, c);
	//printf("前置 d=++e; d:%d e:%d\n", d, e);
	p = a;
	a[0] = 10, a[1] = 20, a[2] = 30;
	printf("*p    ・・・%d\n", *p);
	p = a;
	a[0] = 10, a[1] = 20, a[2] = 30;
	printf("*p+1  ・・・%d\n", *p + 1);
	p = a;
	a[0] = 10, a[1] = 20, a[2] = 30;
	printf("*(p+1)・・・%d\n", *(p + 1));
	p = a;
	a[0] = 10, a[1] = 20, a[2] = 30;
	printf("*p+=1 ・・・%d\n", *p += 1);
	p = a;
	a[0] = 10, a[1] = 20, a[2] = 30;
	printf("------\n");
	printf("*p++  ・・・%d\n", *p++);
	printf("*p    ・・・%d\n", *p);
	p = a;
	a[0] = 10, a[1] = 20, a[2] = 30;
	printf("------\n");
	printf("(*p)++・・・%d\n", (*p)++);
	printf("*p    ・・・%d\n", *p);
	printf("------\n");
		p = a;
	a[0] = 10, a[1] = 20, a[2] = 30;
	printf("*++p  ・・・%d\n", *++p);
	p = a;
	a[0] = 10, a[1] = 20, a[2] = 30;
	printf("++*p  ・・・%d\n", ++ * p);
}