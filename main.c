/*Name : common.h ver 1.1 //
Content : 공통 ANSI의 표준 헤더
프로그램 사용자의 입력을 받고 그에 따른 처리를 담당하도록 구성 //만약 출력하겠다 하면 출력하는 메뉴로 가게 해준다. 
Implementation : HEB //개발자 이름 
Last modified 2018/01/05 //마지막 수정일 
*/

#include "C:\Users\hong\Desktop\c언어_study\winter vacaition\common.h"
#include "C:\Users\hong\Desktop\c언어_study\winter vacaition\screenOut.h"
enum{INPUT = 1, SHOWALL, SEARCH, DELETE, CHANGE, QUIT};//보기 편하게 코딩!! INPUT을 1로 인식함 

int main() {
	int inputMenu = 0;
	
	while(1){
		ShowMenu(); //화면에 메뉴를 표시 
		printf("선택 >>"); 
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
			puts("이용해 주셔서 감사합니다.");
			exit(1);
		}
	} 
	return 0;
}
