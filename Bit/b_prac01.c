#include<stdio.h>
#include<stdlib.h>
#include<time.h> //
#define Skil_Num 3
#define Mob_Num 3
//符号無し整数をUINTで再定義
typedef unsigned int UINT;

typedef struct { //Skill型構造体
	char name[20]; //スキル名
	int type;      //スキルの種類（0: HP回復, 1: AtkUp, 2: 状態異常回復）
	int use_mp;    //使用MP量
	int effect;    //スキル効果
} Skill;
typedef struct { //Spec型構造体
	char name[20]; //名前
	int hp;        //HP
	int atk;       //攻撃力
	int def;       //防御力
	UINT state;    //状態
} Spec;
typedef struct { //Chara型構造体
	Spec sp;       //Spec型構造体変数
	int maxhp;     //最大HP
	int mp;        //SP
	Skill skl[Skil_Num]; //Skill型構造体配列
} Chara;
typedef struct { //Mob型構造体
	Spec sp;       //Spec型構造体変数
	int rate;      //状態異常攻撃発生レート%表記
} Mob;

//列挙型BitStateの宣言
enum BitState
{
	//通常状態
	Base = 0,            //0000 0000 0000 0000
	//(1からいくつ左にシフトするか)
	Poison = 1 << 0,     //0000 0000 0000 0001(どく)
	Sleep = 1 << 1,      //0000 0000 0000 0010(ねむり)
	Paralysis = 1 << 2,  //0000 0000 0000 0100(まひ)
	Burn = 1 << 3,       //0000 0000 0000 1000(やけど)
	AtkUp = 1 << 4,      //0000 0000 0001 0000(攻撃力Up)
	AtkDown = 1 << 5,    //0000 0000 0010 0000(攻撃力Down)
	Dead = 1 << 6        //0000 0000 0100 0000(死亡フラグ)
};

int TurnCount = 0;       //経過ターン(0～999)

//状態を変更する関数
void ChangeFlag(UINT *s);
//状態を回復する関数
void ClearFlag(UINT *s);
//状態を表示する関数
void DisplayStatus(Chara c);

//戦闘時のメニュー表示を行う
int DisplayMenu(void);
//スキル使用時のメニュー表示を行う
int SkillMenu(Chara c);
//戦闘モードへ移行する関数
void BattleMode(Chara* c, Mob m);
//攻撃側と防御側のパラメータを使った攻撃ダメージ計算
int DamageCalc(Spec sp1, Spec sp2);
//戦闘モード時のHP計算と死亡判定
void BattleMessage(Spec sp1, Spec* sp2);

/* b_prac01.exe [数字:0~Mob_Num-1]
* [数字:0~Mob_Num-1]は0からMob_Num-1までの数字を指定して実行することで
* 登場する敵の種類を指定できる。省略した場合は0~Mob_Num-1の乱数となる */
main(int argc,char *argv[])
{
	//乱数列（シード）の初期化
	srand(time(0));
	//自キャラと敵キャラのパラメータ設定
	//未実装項目：データファイルからの読み込み
	//              name    hp    atk  def  state maxhp mp
	Chara chara = { "主人公",2000, 200, 100, Base, 2000, 150, 
    //  sk.name    type usemp effect 
	   {{"HP回復",     0,   50,  800},
		  {"AtkUp",     1,   50,  115},
		  {"状態異常回復",2,   20,    0}} };
	Mob mob[3] = { 
		//name hp   atk def  state   rate%
		{"敵A", 700,150, 800,Poison,  50},
		{"敵B",1500,200, 200,Burn,    50},
		{"ボス",5000,200, 80,AtkDown, 10} };

	//乱数で0~Mob_Num-1の数値を求める
	int num = rand() % Mob_Num;
	//実行時にコマンドライン引数があった場合
	if (argc > 1) {
		//引数を数値に変換
		num = atoi(argv[1]);
		//引数の数値が0~Mob_Num-1の範囲になければ
		if (num < 0 || num >= Mob_Num) {
			//乱数を生成
			num = rand() % Mob_Num;
		}
	} 
	//戦闘モードを開始
	BattleMode(&chara, mob[num]);
	if (chara.sp.state & Dead) {
		printf("%sの死亡によりゲームオーバー\n", chara.sp.name);
	}
}
/*int DamageCalc(Spec sp1, Spec sp2)
* 与ダメ計算関数
* 第1引数：Spec型構造体変数（攻撃側）
* 第2引数：Spec型構造体変数（防御側）
* （与ダメ）＝攻撃側Atk*(攻撃側Atk÷防御側Def）＋攻撃側Atk*乱数0~0.5
* 未実装項目：会心の一撃（通常の1.5倍ダメ）
*/
int DamageCalc(Spec sp1, Spec sp2) {
	return sp1.atk * ((float)sp1.atk / sp2.def) + sp1.atk * (rand() % 50) / 100.0;
}
/*void BattleMessage(Spec sp1, Spec* sp2)
* 戦闘モード時のメッセージ表示を行う
* 第1引数：Spec型構造体変数（攻撃側）
* 第2引数：Spec型構造体変数のアドレス（防御側）
*/
void BattleMessage(Spec sp1, Spec* sp2) {
	int damage;
	TurnCount++;
	printf("%sの攻撃\n", sp1.name);
	damage = DamageCalc(sp1, *sp2);
	printf("%sに%dのダメージ\n\n", sp2->name,damage);
	sp2->hp -= damage;
	if (sp2->hp <= 0) {
		printf("%sは倒された\n", sp2->name);
		sp2->state |= Dead;
	}
}
/*void BattleMode(Chara* c, Mob m)
* 戦闘モード時のメッセージ表示を行う
* 第1引数：Chara型構造体変数のアドレス（自キャラ）
* 第2引数：Mob型構造体変数（敵キャラ）*/
void BattleMode(Chara* c, Mob m) {
	int command, skill;
	system("cls");
	DisplayStatus(*c);
	printf("%sがあらわれた！\n", m.sp.name);
	while (1) {
		command = DisplayMenu();
		if (c->sp.state & Poison) {
			c->sp.hp *= 0.8;
		}
		if (c->sp.state & AtkDown) {
			c->sp.atk *= 0.95;
		}
		if (c->sp.state & Burn) {
			c->sp.hp *= 0.9;
			c->mp *= 0.9;
		}


		if (command == 1) {
			DisplayStatus(*c);
			if (TurnCount % 2 == 0) {
				BattleMessage(c->sp, &m.sp);

				if (m.sp.state & Dead) {
					break;
				}
			}
			if (TurnCount % 2 == 1) {
				BattleMessage(m.sp, &c->sp);
				if (rand() % 100 < m.rate) {
					printf("状態異常攻撃を受けた！\n");
					c->sp.state |= m.sp.state;
				}

				if (c->sp.state & Dead) {
					break;
				}
				else {
					DisplayStatus(*c);
				}
			}
		}
		else if (command == 2) {
			printf("スキルの選択\n");
			skill = SkillMenu(*c);
			//MP残量チェック
			if (c->mp >= c->skl[skill].use_mp) {
				switch (skill) {
				case 0:
					//HPを回復
					c->sp.hp += c->skl[skill].effect;
					//回復量がMAXHPを超えないように
					if (c->sp.hp > c->maxhp) { c->sp.hp = c->maxhp; }
					//MPを減らす
					c->mp -= c->skl[skill].use_mp;
					printf("HPを%d回復した!\n", c->skl[skill].effect);
					DisplayStatus(*c);
					break;
				case 1:
					//ATKを1.15倍
					c->sp.atk *= c->skl[skill].effect / 100.0;
					//MPを減らす
					c->mp -= c->skl[skill].use_mp;
					printf("攻撃力がアップした!\n");
					break;
				default:
					break;
				}
			}
			else {
				printf("MPが足りない！\n");
			}

		}
		//強制終了モード選択時の処理
		else if (command == -1) {
			c->sp.state |= Dead;
			break;
		}
	}
}
/*int DisplayMenu(void)
* 戦闘モード時のコマンド選択画面を表示
* 戻り値：選択したコマンドのメニュー番号 */
int DisplayMenu(void) {
	char ch;
	while (1) {
		printf("----------\nコマンドを選択\n");
		printf("1.たたかう\n2.スキル\n3.ぼうぎょ\n\n");
		ch = getch();
		if (ch > '0' && ch < '4') {
			return ch - '0';
		}
		else if (ch == 'q') { //隠しコマンド：強制終了'q'
			return -1;
		}
	}
}
/*int SkillMenu(Chara c)
* 戦闘モード時のスキル選択画面を表示
* 第1引数：Chara型構造体変数（自キャラ）
* 戻り値：選択したコマンドのメニュー番号 */
int SkillMenu(Chara c) {
	char ch;
	int i;
	while (1) {
		printf("----------\nスキルを選択\n");
		for (i = 0; i < Skil_Num; i++) {
			printf("%d.%s\n", i + 1, c.skl[i].name);
		}
		printf("\n");
		ch = getch();
		if (ch > '0' && ch < '4') {
			return ch - '0' - 1;
		}
	}
}

/*void DisplayStatus(Chara c)
* 戦闘モード時の自キャラのステータス表示
* 第1引数：Chara型構造体変数（自キャラ）*/
void DisplayStatus(Chara c) {
	printf("******************\n");
	//HPとMP表示
	printf("HP:%-4d  MP:%-3d\n",c.sp.hp, c.mp);
	//フラグが立っているビットの確認
	if (c.sp.state) {
		printf("状態： ");
		if (c.sp.state & Poison) { printf("毒 "); }
		if (c.sp.state & Sleep)  { printf("睡眠 "); }
		if (c.sp.state & Paralysis) { printf("麻痺 "); }
		if (c.sp.state & Burn)   { printf("火傷 "); }
		if (c.sp.state & AtkUp)  { printf("攻撃力アップ "); }
		if (c.sp.state & AtkDown){ printf("攻撃力ダウン"); }
	}
	printf("\n******************\n");
}
void ChangeFlag(UINT* s) {
	int a;
	while (1) {
		printf("どの状態にしますか？\n");
		printf("1:毒 2:睡眠 3:麻痺 4:火傷 5:攻撃↑ 6:攻撃↓ 0:入力終了＞");
		scanf("%d",&a);
		if (a == 0) {
			break;
		}
		switch (a) {
			case 1: *s |= Poison; break;
			case 2: *s |= Sleep;  break;
			case 3: *s |= Paralysis; break;
			case 4: *s |= Burn;   break;
			case 5:	*s |= AtkUp;  break;
			case 6: *s |= AtkDown;break;
		}
	}
}
void ClearFlag(UINT* s) {
	int ch;
	while (1) {
		printf("どの状態を回復しますか？\n");
		printf("1:毒 2:睡眠 3:麻痺 4:火傷 5:攻撃↑ 6:攻撃↓ 0:入力終了＞");
		scanf("%d", &ch);
		switch (ch) {
		case 1:
			*s &= ~Poison;
			break;
		case 2:
			*s &= ~Sleep;
			break;
		case 3:
			*s &= ~Paralysis;
			break;
		case 4:
			*s &= ~Burn;
			break;
		case 5:
			*s &= ~AtkUp;
			break;
		case 6:
			*s &= ~AtkDown;
			break;
		}
		if (ch == 0) {
			break;
		}
	}
}