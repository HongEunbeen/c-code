#include "C:\Users\hong\Desktop\c���_study\winter vacaition\common.h"
#include "C:\Users\hong\Desktop\c���_study\winter vacaition\game.h"
#include "C:\Users\hong\Desktop\c���_study\winter vacaition\gameMoney.h"
static int count;
static int win;
int ChoiceOfCom(){
	int random;
	srand((int)time(NULL)); // rand�� �ð��� ���� �ٸ� ���� ����!!! 
	return rand()%3+1;
}
int ChoiceOfMe(){
	int choice;
	printf("����(1) ����(2) ��(3) ����(4) �� �����ϼ���\n");
	scanf("%d",&choice);
	printf("\n");
	return choice;
}
void WhoIsWinner(com,you){
	count++;
	printf("��ǻ���� �� : ");
	ShowRSP(com);
	printf("���� �� : ");
	ShowRSP(you); 
	switch(you-com){
		case 0: printf("�����ϴ�.\n"); break;
		case -2: case 1:
		printf("����ڰ� �̱�̽��ϴ�.\n");
		win++; 
		YouWinMoneyAccount();break;
		default : printf("����ڰ� ���̽��ϴ�.\n"); ComWinMoneyAccount();break;
	}
	printf("�·��� : %.0f %%�Դϴ�.\n",(float)win/count*100);
	return;
}
void ShowRSP(int rsp){
	switch(rsp){
		case SCISSORS:
			puts("����");
			break;
		case ROCK:
			puts("����");
			break;
		case PAPER:
			puts("��");
			break;
	}
}
