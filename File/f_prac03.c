#include<stdio.h>
typedef struct {
	char Wname[20];
	int bullet;
	float atk;
} Weapon;
typedef struct {
	char name[20];
	int hp;
	Weapon wpn;
} Soldier;
void SetInfo(Soldier* s, char* filename);
void Display(Soldier s);
main()
{
	Soldier sol;
	SetInfo(&sol, "file03.txt");
	Display(sol);
}
void SetInfo(Soldier* s, char* filename) {
	FILE* fp;
	if (fp = fopen(filename, "r")) {
		fscanf(fp, "%s%d%s%d%f", s->name, &s->hp,
			s->wpn.Wname, &s->wpn.bullet, &s->wpn.atk);
		fclose(fp);
	}
	else {
		printf("“Ç‚İ‚İƒGƒ‰[\n");
		return;
	}
}
void Display(Soldier s) {
	printf("%s ‘Ì—Í:%d\n", s.name, s.hp);
	printf("•Ší:%s ’e”:%d UŒ‚—Í:%.2f\n", 
		s.wpn.Wname, s.wpn.bullet, s.wpn.atk);
}