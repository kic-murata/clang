#include<stdio.h>
#define TBL_END 5	//ƒ}ƒNƒ’è‹`
int tbl_gokei4(int* p);
main()
{
	int a[] = { 10,20,30,40,50 }, gokei;
	gokei = tbl_gokei4(a);
	printf("gokei = %d\n", gokei);
}
int tbl_gokei4(int* p) {
	int i, gokei = 0;
	for (i = 0; i < TBL_END; i++) {
		gokei += *(p + i);	// gokei+=*p++;‚Å‚à‰Â
	}
	return(gokei);
}