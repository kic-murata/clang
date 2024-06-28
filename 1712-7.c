#include<stdio.h>

//extern void put_led_number(int offset, unsigned short bit);
#define LED_MINUS 10
#define LED_SPACE 11
#define DOT_BIT 0x80

unsigned short led[][7] = {
	{1,1,1,0,1,1,1},	// 0
	{0,0,1,0,0,1,0},	// 1 
	{1,0,1,1,1,0,1},	// 2
	{1,0,1,1,0,1,1},	// 3
	{0,1,1,1,0,1,0},	// 4
	{1,1,0,1,0,1,1},	// 5
	{1,1,0,1,1,1,1},	// 6
	{1,0,1,0,0,1,0},	// 7
	{1,1,1,1,1,1,1},	// 8
	{1,1,1,1,0,1,1},	// 9
	{0,0,0,1,0,0,0},	// -
	{0,0,0,0,0,0,0}		// ‹ó”’
};

void put_led_number(int offset, unsigned short bit)
{
	printf("%d:%x\n", offset, bit);
	int seg[8];
	int i;
	for (i = 0; i < 8; i++) {
		seg[7-i] = bit % 2;
		bit /= 2;
	}
	//for (i = 0; i < 8; i++) {
	//	printf("%d",seg[i]);
	//}
	if (seg[1]) {
		printf("@@@\n");
	}
	else {
		printf("\n");
	}
	if (seg[2] && seg[3]) {
			printf("@ @\n@ @\n");
		}
		else if(seg[2]&&!seg[3]) {
			printf("@\n@\n");
		} 
		else if(!seg[2]&&seg[3]){
				printf("  @\n  @\n");
		}
	if (seg[4]) {
		printf("@@@\n");
	}
}

unsigned short make_led_number(int number, int dot) {
	int i;
	unsigned short bit = 0x00;
	for (i = 6; i >= 0; i--) {
		bit <<= 1;
		bit |= led[number][i];
	}
	if (dot == 1) {
		bit |= DOT_BIT;
	}
	return bit;
}
void display_led(char numbers[]) {
	int i, n, dot;
	for (i = 0; i < 4; i++) {
		printf("numbers[i]:%c\n", numbers[i]);
		if (numbers[i] == '-') {
			n = LED_MINUS;
		}
		else if (numbers[i] == ' ') {
			n = LED_SPACE;
		}
		else {
			n = numbers[i] - '0';
		}
		dot = (i == 2) ? 1 : 0;
		printf("n:%d dot:%d\n", n, dot);
		put_led_number(i, make_led_number(n, dot));
	}
}
int main(void) {
	char num[5];
	printf("”’l“ü—Í„");
	gets(num);
	//scanf("%s", num);
	display_led(num);
	printf("A");
	return 0;
}