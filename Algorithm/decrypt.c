#include<stdio.h>
main()
{
	char s[20];
	int i = 0;
	printf("ˆÃ†‰»•¶š—ñ‚ğ“ü—Í„");
	scanf("%s", &s[0]);
	while (s[i] != '\0') {
		s[i] -= 1;	// s[i] = s[i] - 1
		i++;				// i = i + 1
	}
	printf("•œ†Ï•¶š—ñ‚Í%s\n", s);
}