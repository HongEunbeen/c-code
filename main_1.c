#include "C:\Users\hong\Desktop\c언어_study\winter vacaition\common_1.h"
#include "C:\Users\hong\Desktop\c언어_study\winter vacaition\game.h"
#include "C:\Users\hong\Desktop\c언어_study\winter vacaition\gameMoney.h"
int main() {
	
	int com;
	int you;
	int input,pan;
	printf("게임을 시작합니다\n");
	printf("당신의 머니를 입력하세요 : ");
	scanf("%d",&input);
	SetComMoney(1000);
	SetYouMoney(input);
	printf("당신의 게임머니 : %d\n",GetCurrentYouMoney()); 
	printf("컴퓨터의 게임머니 : %d\n",GetCurrentComMoney()); 
	while(1){
		puts("------대결-------\n\n"); 
		printf("판돈 설정합니다!");
		scanf("%d",&pan);
		SetPandon(pan);
		if(pan > GetCurrentYouMoney()){
			printf("소유하고 있는 금액 내에거 거세요\n");
			continue; 
		}
		else if(pan >GetCurrentComMoney() ){
			printf("컴퓨터내에 금액이 없습니다.\n");
			continue;
		}
		com = ChoiceOfCom();//컴퓨터 값 
		you = ChoiceOfMe();// 내가 선택한 값
		if(you == 4){
			break;
		}
		puts("------결과-------\n"); 
		WhoIsWinner(com,you);
		printf("게이머 머니 : %d\n",GetCurrentYouMoney());
		printf("컴퓨터 머니 : %d\n",GetCurrentComMoney());
		if(GetCurrentYouMoney() <= 0|| GetCurrentComMoney() <= 0){
			break;
		}
	}
	 
} 
