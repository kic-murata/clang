#include<stdio.h>
main()
{
	char* p_game[] = { "wii","ds","playstation4" };
	char** p;			// �|�C���^�̃|�C���^
	int i;
	p = p_game;		// �|�C���^�Ƀ|�C���^�z��̐擪�A�h���X����
	for (i = 0; i < 3; i++) {
		printf("%s\n", *p++);
	}
	// ---- �ȍ~�̓A�h���X�m�F�p ----
	p = p_game;
	printf(" p_game[0]:%d\n", p_game[0]);
	printf(" p_game[1]:%d\n", p_game[1]);
	printf(" p_game[2]:%d\n", p_game[2]);
	printf("        *p:%d\n", *p       );
	printf("    *(p+1):%d\n", *(p + 1) );
	printf("    *(p+2):%d\n", *(p + 2) );
	printf("*p_game[0]:%c\n", *p_game[0]);
	printf("       **p:%c\n", **p       );
}