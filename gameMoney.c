#include "C:\Users\hong\Desktop\c���_study\winter vacaition\common_1.h"
#include "C:\Users\hong\Desktop\c���_study\winter vacaition\game.h"
#include "C:\Users\hong\Desktop\c���_study\winter vacaition\gameMoney.h"
static int moneyCom;
static int moneyYou;
static int pandon;
void SetComMoney(int money){
	if(money < 0){
		puts("���ӸӴϰ� �����մϴ�.");
		return; 
	}
	moneyCom = money;
}
void SetYouMoney(int money){
	if(money < 0){
		puts("���ӸӴϰ� �����մϴ�.");
		return; 
	}
	moneyYou = money;
}
void SetPandon(int money){
	if(money < 0){
		pandon = 0;
	}
	else{
		pandon = money;
	}
}
void ComWinMoneyAccount(){
	moneyCom += pandon;
	moneyYou -= pandon;
}
void YouWinMoneyAccount(){
	moneyYou += pandon;
	moneyCom -= pandon;
}
int GetCurrentComMoney(){
	return moneyCom;
}
int GetCurrentYouMoney(){
	return moneyYou;
}
