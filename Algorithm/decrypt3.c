#include<stdio.h>
main()
{
	int i=0;
	char s[21], k[21];
	printf("�Í������������́�");
	scanf("%s", &s[0]);
	printf("�����L�[����́�");
	scanf("%s", &k[0]);
	while (s[i] != '\0') {
		s[i] = s[i] - (k[i]-'0');
		i++;
	}
	printf("�����ϕ�����́A%s", s);
}