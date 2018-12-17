#include<stdio.h>//standared input, output의 약자 
#include<stdlib.h> 
#include<string.h>

typedef struct node{
	char title[50];
	int year;
	struct node *link;
}NODE;//하나의 연결 리스트 들을 node라고 부른다. 
int main(){
	NODE *p;
	NODE *list = NULL;
	NODE *prev;
	NODE *next;//동적메모리를 날리기 위한 포인터 
	char buffer[50];
	int year;
	//연결 리스트에 정보를 입력한다. 
	while(1){
		printf("책의 제목을 입력하시오.");
		gets(buffer);
		if(buffer[0] == '\0'){
			break;
		}
		p =	(NODE*)malloc(sizeof(NODE));// p를 계속해서 생성 
		strcpy(p->title,buffer);
		
		printf("출판 연도를 입력하시오.");
		gets(buffer);
		p->year = atoi(buffer); //문자열 -> 숫자로 변환
		//정해져 있는 연결리스트 알고리즘 30~41 고정된 코드 
		if(list == NULL){
			list = p;
		}
		else {
			prev->link = p;//prev 이전 주소를 기억하게 하기 위해 prev선언  
		}
		p->link = NULL;//끝이라고 알리기 위해 NULL 삽입  
		prev = p;//p가 다시 주소를 갖기 전해 이전 로드에게 알려주어야 됌 
	}	
	printf("\n");
	
	p = list;
	while(p != NULL){
		printf("책 제목 : %s\n출판년도 : %d\n",p->title,p->year);
		p = p->link;
	}
	
	//동적메모리 할당한거 날려버리기 위해서 처음부터 다시 날려야됌 
	p = list;//p가 다시 맨 처음으로 돌아옴 
	while(p != null){//마지막 문장까지 돔 
		next = p->link;//다음 주소를 먼저 저장한 다음 원래 주소를 없애기	
		free(p);//스스로 사라짐 
		p = next;//다음 주소를 다시 저장 
	}
	
}
