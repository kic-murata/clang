#include<stdio.h>
main()
{
	int i=0;
	char s[21], k[21];
	printf("ˆÃ†‰»•¶š—ñ‚ğ“ü—Í„");
	scanf("%s", &s[0]);
	printf("•œ†ƒL[‚ğ“ü—Í„");
	scanf("%s", &k[0]);
	while (s[i] != '\0') {
		s[i] = s[i] - (k[i]-'0');
		i++;
	}
	printf("•œ†Ï•¶š—ñ‚ÍA%s", s);
}