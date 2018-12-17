#include "C:\Users\hong\Desktop\c언어_study\winter vacaition\common.h"
#include "C:\Users\hong\Desktop\c언어_study\winter vacaition\game.h"
#include "C:\Users\hong\Desktop\c언어_study\winter vacaition\gameMoney.h"
static int count;
static int win;
int ChoiceOfCom(){
	int random;
	srand((int)time(NULL)); // rand가 시간에 따라 다른 값을 뱉어내게!!! 
	return rand()%3+1;
}
int ChoiceOfMe(){
	int choice;
	printf("가위(1) 바위(2) 보(3) 종료(4) 중 선택하세요\n");
	scanf("%d",&choice);
	printf("\n");
	return choice;
}
void WhoIsWinner(com,you){
	count++;
	printf("컴퓨터의 값 : ");
	ShowRSP(com);
	printf("나의 값 : ");
	ShowRSP(you); 
	switch(you-com){
		case 0: printf("비겼습니다.\n"); break;
		case -2: case 1:
		printf("사용자가 이기셨습니다.\n");
		win++; 
		YouWinMoneyAccount();break;
		default : printf("사용자가 지셨습니다.\n"); ComWinMoneyAccount();break;
	}
	printf("승률은 : %.0f %%입니다.\n",(float)win/count*100);
	return;
}
void ShowRSP(int rsp){
	switch(rsp){
		case SCISSORS:
			puts("가위");
			break;
		case ROCK:
			puts("바위");
			break;
		case PAPER:
			puts("보");
			break;
	}
}
