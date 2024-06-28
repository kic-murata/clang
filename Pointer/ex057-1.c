#include<stdio.h>
main()
{
	int tbl[][3] = { {10,20,30},{40,50,60},{70,80,90} };
	int* p_tbl, i;
	p_tbl = tbl[1];
	printf("tbl‚Ì‚Ps–Ú‚Ì“à—e\n");
	for (i = 0; i < 3; i++) {
		printf(" %d", *(p_tbl+i));
		//printf(" %d", *p_tbl++);
		//printf(" %d", *p_tbl); p_tbl++;
	}
}