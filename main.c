/*Name : common.h ver 1.1 //
Content : ���� ANSI�� ǥ�� ���
���α׷� ������� �Է��� �ް� �׿� ���� ó���� ����ϵ��� ���� //���� ����ϰڴ� �ϸ� ����ϴ� �޴��� ���� ���ش�. 
Implementation : HEB //������ �̸� 
Last modified 2018/01/05 //������ ������ 
*/

#include "C:\Users\hong\Desktop\c���_study\winter vacaition\common.h"
#include "C:\Users\hong\Desktop\c���_study\winter vacaition\screenOut.h"
enum{INPUT = 1, SHOWALL, SEARCH, DELETE, CHANGE, QUIT};//���� ���ϰ� �ڵ�!! INPUT�� 1�� �ν��� 

int main() {
	int inputMenu = 0;
	
	while(1){
		ShowMenu(); //ȭ�鿡 �޴��� ǥ�� 
		printf("���� >>"); 
		scanf("%d",&inputMenu);
		fflush(stdin);
		
		switch(inputMenu) {
			case INPUT: 
				InputPhoneData();
				break;
			case SHOWALL:
				ShowAllData();
				break;
			case SEARCH :
				SearchPhoneData();
				break;
			case DELETE :
				DeletePhoneData();
				break; 
			case CHANGE : 
				ChangePhoneData();
				break;
		}
		if(inputMenu == QUIT){
			puts("�̿��� �ּż� �����մϴ�.");
			exit(1);
		}
	} 
	return 0;
}
