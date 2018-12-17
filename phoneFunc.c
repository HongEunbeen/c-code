#include "C:\Users\hong\Desktop\c언어_study\winter vacaition\common.h"
#include "C:\Users\hong\Desktop\c언어_study\winter vacaition\phoneData.h"
#define LIST_NUM 100

int numofData = 0;
//phoneData phoneList[LIST_NUM];//정적할당 
phoneData *phoneList[LIST_NUM];//동적할당 
void InputPhoneData(){
	//phoneData data;
	phoneData *pData;//새로운 공간을 만들어서 배열에 집어넣는 이유는 유효성 검사 때문이다. 
	int i;
	if(numofData >= LIST_NUM){
		puts("메모리 공간이 부족합니다."); 
	}
	pData = (phoneData *)malloc(sizeof(phoneData));
	
	printf("이름 입력 : ");
	//gets(data.name);
	gets(pData->name);
	printf("\n전화번호 입력 : ");
	//gets(data.phoneNum);
	gets(pData->phoneNum);
	for(i = 0; i < numofData; i++){
		if(strcmp(pData->name,phoneList[i]->name) == 0 && strcmp(pData->phoneNum,phoneList[i]->phoneNum) == 0){
			puts("이미 입력된 데이터 입니다");
			free(pData);
			getchar();
			return;
		}
	}
	phoneList[numofData] = pData;
	numofData++;
	printf("입력이 완료 되었습니다");
	getchar();
	
	 
	//phoneList[numofData] = data;
	
}

void ShowAllData(){
	int i;
	for(i = 0; i < numofData; i++){
		//ShowPhoneInfo(phoneList[i]);
		ShowPhoneInfoByPtr(phoneList[i]);
	}
	printf("출력 완료되었습니다");
	getchar();
}

void SearchPhoneData(){
	int i;
	char sa[30];
	printf("검색하실 이름을 입력해 주세요 : ");
	gets(sa);
	int searchStr = 0;
	for(i = 0; i < numofData; i++){
		if(strcmp(sa,phoneList[i]->name) == 0){
			ShowPhoneInfoByPtr(phoneList[i]);
			searchStr = 1;
		}
	}
	if(searchStr == 0){
		puts("데이터 존재하지 않는다.\a");
	}
	else{
		puts("검색 완료"); 
	}
	getchar(); 
	
}
void DeletePhoneData(){
	char sa[100];
	int i,j,matchedCount = 0,delIdx = 0,selection = 0;
	int idxOfMatchigData[LIST_NUM];// 같은 이름을 저장하려는 배열을 가지게 하기 위해서 
	printf("삭제하실 이름을 입력해 주세요 : ");
	gets(sa);
	for(i= 0; i < numofData; i++){
		if((strcmp(phoneList[i]->name, sa)) == 0){
			idxOfMatchigData[matchedCount++] = i;
		}
	} 
	if(matchedCount == 0){
		printf("삭제하실 이름이 목록에 없습니다."); 
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
		puts("삭제하실 이름을 번호로 선택해주세요");
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
	printf("삭제되었습니다");
*/	getchar(); 
}
void ChangePhoneData(){
	char input[LIST_NUM], inputnum[LIST_NUM];
	int idxOfChangeMatchigData[LIST_NUM];
	int ChangematchedCount = 0; 
	int i,ChangedelIdx = 0,selection;
	printf("대상의 이름은?");
	gets(input);
	for(i= 0; i < numofData; i++){
		if((strcmp(phoneList[i]->name, input)) == 0){
			idxOfChangeMatchigData[ChangematchedCount++] = i;//중요  
		}
	} 
	if(ChangematchedCount == 0){
		printf("목록에 없는 이름입니다."); 
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
	printf("변경할 전화번호를 입력해 주세요\n");
	gets(inputnum);
	for(i = 0; i < numofData; i++){
		if(strcmp(inputnum, phoneList[i]->phoneNum)  == 0 && strcmp(input, phoneList[i]->name) == 0){
			puts("이미 있는 목록입니다");
			getchar();
			return;
		}
	} 
	strcpy(phoneList[ChangedelIdx]->phoneNum,inputnum); 
	printf("변경되었습니다");
	getchar();
	
}
