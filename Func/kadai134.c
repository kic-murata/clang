#include<stdio.h>
main() {
	char buf[20], * ret;
	printf("���́�");
	while (gets(buf) != NULL) {
		printf("ret:%d buf:%d\n", ret, buf);
		puts(buf);
		printf("���́�");
	}
}