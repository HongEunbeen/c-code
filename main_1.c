#include "C:\Users\hong\Desktop\c���_study\winter vacaition\common_1.h"
#include "C:\Users\hong\Desktop\c���_study\winter vacaition\game.h"
#include "C:\Users\hong\Desktop\c���_study\winter vacaition\gameMoney.h"
int main() {
	
	int com;
	int you;
	int input,pan;
	printf("������ �����մϴ�\n");
	printf("����� �Ӵϸ� �Է��ϼ��� : ");
	scanf("%d",&input);
	SetComMoney(1000);
	SetYouMoney(input);
	printf("����� ���ӸӴ� : %d\n",GetCurrentYouMoney()); 
	printf("��ǻ���� ���ӸӴ� : %d\n",GetCurrentComMoney()); 
	while(1){
		puts("------���-------\n\n"); 
		printf("�ǵ� �����մϴ�!");
		scanf("%d",&pan);
		SetPandon(pan);
		if(pan > GetCurrentYouMoney()){
			printf("�����ϰ� �ִ� �ݾ� ������ �ż���\n");
			continue; 
		}
		else if(pan >GetCurrentComMoney() ){
			printf("��ǻ�ͳ��� �ݾ��� �����ϴ�.\n");
			continue;
		}
		com = ChoiceOfCom();//��ǻ�� �� 
		you = ChoiceOfMe();// ���� ������ ��
		if(you == 4){
			break;
		}
		puts("------���-------\n"); 
		WhoIsWinner(com,you);
		printf("���̸� �Ӵ� : %d\n",GetCurrentYouMoney());
		printf("��ǻ�� �Ӵ� : %d\n",GetCurrentComMoney());
		if(GetCurrentYouMoney() <= 0|| GetCurrentComMoney() <= 0){
			break;
		}
	}
	 
} 
