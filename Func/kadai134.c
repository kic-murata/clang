#include<stdio.h>
main() {
	char buf[20], * ret;
	printf("“ü—Í„");
	while (gets(buf) != NULL) {
		printf("ret:%d buf:%d\n", ret, buf);
		puts(buf);
		printf("“ü—Í„");
	}
}