/*Name : common.h ver 1.2 //수정 한번도 안했다는 뜻의 1.0 
Content : 공통 ANSI의 표준 헤더 
Implementation : HEB//개발자 이름 
Last modified 2018/01/05 //마지막 수정일 
*/
#include "C:\Users\hong\Desktop\c언어_study\winter vacaition\common.h"
#include "C:\Users\hong\Desktop\c언어_study\winter vacaition\phoneData.h"

void ShowMenu(){
	system("cls");//화면을 깨끗하게 지우겠다.
	
	printf("------------------메뉴------------------\n") ;
	printf("1. 전화번호 입력\n");
	printf("2. 전체 정보 출력\n");
	printf("3. 전화번호 검색\n");
	printf("4. 전화번호 삭제\n");
	printf("5. 전화번호 수정\n");
	printf("6. 종료\n");
	printf("----------------------------------------\n");

} 
void ShowPhoneInfo(phoneData phone){
	printf("┌--------------------------(ΘωΘ)\n"); 
	printf("│  ▶ 이름 : %s\n",phone.name);
	printf("│  ▶ 전화번호 : %s\n",phone.phoneNum);
	printf("└----------------------------------\n");
}//동적메모리 x 

void ShowPhoneInfoByPtr(phoneData *pPhone){
	printf("┌--------------------------(ΘωΘ)\n"); 
	printf("│  ▶ 이름 : %s\n",pPhone->name);
	printf("│  ▶ 전화번호 : %s\n",pPhone->phoneNum);
	printf("└----------------------------------\n");
}
