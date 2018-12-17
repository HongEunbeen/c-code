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
	char buffer[50];
	int year;
	//연결 리스트에 정보를 입력한다. 
	while(1){
		printf("책의 제목을 입력하시오.");
		gets(buffer);
		if(buffer[0] == '\0'){
			break;
		}
		p =	(NODE*)malloc(sizeof(NODE));
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
	free(p);
}

