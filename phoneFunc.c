#include "C:\Users\hong\Desktop\c���_study\winter vacaition\common.h"
#include "C:\Users\hong\Desktop\c���_study\winter vacaition\phoneData.h"
#define LIST_NUM 100

int numofData = 0;
//phoneData phoneList[LIST_NUM];//�����Ҵ� 
phoneData *phoneList[LIST_NUM];//�����Ҵ� 
void InputPhoneData(){
	//phoneData data;
	phoneData *pData;//���ο� ������ ���� �迭�� ����ִ� ������ ��ȿ�� �˻� �����̴�. 
	int i;
	if(numofData >= LIST_NUM){
		puts("�޸� ������ �����մϴ�."); 
	}
	pData = (phoneData *)malloc(sizeof(phoneData));
	
	printf("�̸� �Է� : ");
	//gets(data.name);
	gets(pData->name);
	printf("\n��ȭ��ȣ �Է� : ");
	//gets(data.phoneNum);
	gets(pData->phoneNum);
	for(i = 0; i < numofData; i++){
		if(strcmp(pData->name,phoneList[i]->name) == 0 && strcmp(pData->phoneNum,phoneList[i]->phoneNum) == 0){
			puts("�̹� �Էµ� ������ �Դϴ�");
			free(pData);
			getchar();
			return;
		}
	}
	phoneList[numofData] = pData;
	numofData++;
	printf("�Է��� �Ϸ� �Ǿ����ϴ�");
	getchar();
	
	 
	//phoneList[numofData] = data;
	
}

void ShowAllData(){
	int i;
	for(i = 0; i < numofData; i++){
		//ShowPhoneInfo(phoneList[i]);
		ShowPhoneInfoByPtr(phoneList[i]);
	}
	printf("��� �Ϸ�Ǿ����ϴ�");
	getchar();
}

void SearchPhoneData(){
	int i;
	char sa[30];
	printf("�˻��Ͻ� �̸��� �Է��� �ּ��� : ");
	gets(sa);
	int searchStr = 0;
	for(i = 0; i < numofData; i++){
		if(strcmp(sa,phoneList[i]->name) == 0){
			ShowPhoneInfoByPtr(phoneList[i]);
			searchStr = 1;
		}
	}
	if(searchStr == 0){
		puts("������ �������� �ʴ´�.\a");
	}
	else{
		puts("�˻� �Ϸ�"); 
	}
	getchar(); 
	
}
void DeletePhoneData(){
	char sa[100];
	int i,j,matchedCount = 0,delIdx = 0,selection = 0;
	int idxOfMatchigData[LIST_NUM];// ���� �̸��� �����Ϸ��� �迭�� ������ �ϱ� ���ؼ� 
	printf("�����Ͻ� �̸��� �Է��� �ּ��� : ");
	gets(sa);
	for(i= 0; i < numofData; i++){
		if((strcmp(phoneList[i]->name, sa)) == 0){
			idxOfMatchigData[matchedCount++] = i;
		}
	} 
	if(matchedCount == 0){
		printf("�����Ͻ� �̸��� ��Ͽ� �����ϴ�."); 
		getchar();
		return;
	}
	else if(matchedCount == 1){
		delIdx = idxOfMatchigData[0];
	}
	else{
		for(i = 0; i < matchedCount; i++){
			printf("NUM. %d\n",i+1);
			ShowPhoneInfoByPtr(phoneList[idxOfMatchigData[i]]);
		}
		puts("�����Ͻ� �̸��� ��ȣ�� �������ּ���");
		scanf("%d",&selection);
		delIdx = idxOfMatchigData[selection - 1];
	}
	free(phoneList[delIdx]);
	
	for(j = delIdx; j < numofData; j++){
		phoneList[j] = phoneList[j+1];
	}
	numofData--;
/*	for(i = 0; i < numofData; i++){
		if(strcmp(sa,phoneList[i]->name) == 0){
			ShowPhoneInfoByPtr(phoneList[i]);
			DeletePhone(i);
			numofData--;
		}
	}
	printf("�����Ǿ����ϴ�");
*/	getchar(); 
}
void ChangePhoneData(){
	char input[LIST_NUM], inputnum[LIST_NUM];
	int idxOfChangeMatchigData[LIST_NUM];
	int ChangematchedCount = 0; 
	int i,ChangedelIdx = 0,selection;
	printf("����� �̸���?");
	gets(input);
	for(i= 0; i < numofData; i++){
		if((strcmp(phoneList[i]->name, input)) == 0){
			idxOfChangeMatchigData[ChangematchedCount++] = i;//�߿�  
		}
	} 
	if(ChangematchedCount == 0){
		printf("��Ͽ� ���� �̸��Դϴ�."); 
		getchar();
		return;
	}
	else if(ChangematchedCount == 1){
		ChangedelIdx = idxOfChangeMatchigData[0];
	}
	else{
		for(i = 0; i < ChangematchedCount; i++){
			printf("NUM. %d\n",i+1);
			ShowPhoneInfoByPtr(phoneList[idxOfChangeMatchigData[i]]);
		}
		scanf("%d",&selection);
		ChangedelIdx = idxOfChangeMatchigData[selection - 1];
	}
	fflush(stdin);
	printf("������ ��ȭ��ȣ�� �Է��� �ּ���\n");
	gets(inputnum);
	for(i = 0; i < numofData; i++){
		if(strcmp(inputnum, phoneList[i]->phoneNum)  == 0 && strcmp(input, phoneList[i]->name) == 0){
			puts("�̹� �ִ� ����Դϴ�");
			getchar();
			return;
		}
	} 
	strcpy(phoneList[ChangedelIdx]->phoneNum,inputnum); 
	printf("����Ǿ����ϴ�");
	getchar();
	
}
