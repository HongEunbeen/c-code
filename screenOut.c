/*Name : common.h ver 1.2 //���� �ѹ��� ���ߴٴ� ���� 1.0 
Content : ���� ANSI�� ǥ�� ��� 
Implementation : HEB//������ �̸� 
Last modified 2018/01/05 //������ ������ 
*/
#include "C:\Users\hong\Desktop\c���_study\winter vacaition\common.h"
#include "C:\Users\hong\Desktop\c���_study\winter vacaition\phoneData.h"

void ShowMenu(){
	system("cls");//ȭ���� �����ϰ� ����ڴ�.
	
	printf("------------------�޴�------------------\n") ;
	printf("1. ��ȭ��ȣ �Է�\n");
	printf("2. ��ü ���� ���\n");
	printf("3. ��ȭ��ȣ �˻�\n");
	printf("4. ��ȭ��ȣ ����\n");
	printf("5. ��ȭ��ȣ ����\n");
	printf("6. ����\n");
	printf("----------------------------------------\n");

} 
void ShowPhoneInfo(phoneData phone){
	printf("��--------------------------(�ȥ���)\n"); 
	printf("��  �� �̸� : %s\n",phone.name);
	printf("��  �� ��ȭ��ȣ : %s\n",phone.phoneNum);
	printf("��----------------------------------\n");
}//�����޸� x 

void ShowPhoneInfoByPtr(phoneData *pPhone){
	printf("��--------------------------(�ȥ���)\n"); 
	printf("��  �� �̸� : %s\n",pPhone->name);
	printf("��  �� ��ȭ��ȣ : %s\n",pPhone->phoneNum);
	printf("��----------------------------------\n");
}
