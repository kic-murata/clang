#include<stdio.h>
struct profile {
	char name[20];
	int birth[3];
	char blood[5];
};
void disp(struct profile data);
main()
{
	struct profile data;
	printf("–¼‘O‚ğ“ü—ÍF");
	gets(data.name);
	printf("¶”NŒ“ú‚ğ‹ó”’‚Å‹æØ‚Á‚Ä“ü—ÍF");
	scanf("%d%d%d", &data.birth[0], &data.birth[1], &data.birth[2]);
	printf("ŒŒ‰tŒ^‚ğ“ü—ÍF");
	scanf("%s", data.blood);
	disp(data);
}
void disp(struct profile data) {
	printf("%s - %d”N%dŒ%d“ú¶@ŒŒ‰tŒ^ - %sŒ^\n",
		data.name,
		data.birth[0], data.birth[1], data.birth[2],
		data.blood);
}