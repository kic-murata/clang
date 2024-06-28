#include<stdio.h>
int strcnt(char* p);
main()
{
	char buf[256];
	int mojisu;
	printf("•¶š—ñH");
	gets(buf);
	mojisu = strcnt(buf);
	printf("“ü—Í•¶š—ñ‚Ì•¶š”‚Í%d•¶š‚Å‚·\n", mojisu);
}
int strcnt(char* p) {
	int cnt;
	for (cnt = 0; *p != '\0'; cnt++, p++);
	/* while‚Å‘‚­ê‡
	cnt = 0;
	while (*p != '\0') {
		cnt++;
		p++;
	}
	*/
	return(cnt);
}