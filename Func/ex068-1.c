#include<stdio.h>
main()
{
	int a, b, c, ret;
	printf("���l���R����:");
	ret = scanf("%d%d%d", &a, &b, &c);
	printf("ret:%d\ta:%d\tb:%d\tc:%d\n", ret, a, b, c);

	printf("���l�������(Ctrl+Z�ŏI���j�F");
	while(scanf("%d", &a)�@!=�@EOF){
		printf("���l�F%d\n", a);
		printf("���l�������(Ctrl+Z�ŏI���j�F");
	}
}