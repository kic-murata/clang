#include<stdio.h>
enum BitState {
	Base = 0,						//00000000�@�ʏ�
	Poison = 1 << 0,		//00000001�@�ǂ�
	Sleep = 1 << 1,			//00000010�@�˂ނ�
	Paralysis = 1 << 2,	//00000100	�܂�
	Burn = 1 << 3,			//00001000	�₯��
	AtkUp = 1 << 4,			//00010000�@�U���̓A�b�v
	AtkDown = 1 << 5		//00100000�@�U���̓_�E��
};
typedef unsigned int UINT;
void DisplayStatus(UINT s);
void ChangeFlag(UINT* s);
void ClearFlag(UINT* s);
main()
{
	UINT MyState = Base;
	ChangeFlag(&MyState);
	DisplayStatus(MyState);
	ClearFlag(&MyState);
	DisplayStatus(MyState);
}
void DisplayStatus(UINT s) {

}
void ChangeFlag(UINT* s) {

}
void ClearFlag(UINT* s) {

}
