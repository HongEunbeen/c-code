#include<stdio.h>
struct student{
	int number;
	char name[20];
	double grade;
};
int main(){
	struct student s = {200,"홍길동",5.0};
	
	struct student *p;//구조체를 가르키는 포인터
	p = &s; 
	
	printf("학번 : %d, 이름 :  %s, 학점 :  %.2lf\n",s.number, s.name, s.grade);
	printf("학번 : %d, 이름 :  %s, 학점 :  %.2lf\n",p->number, p->name, p->grade);
	printf("학번 : %d, 이름 :  %s, 학점 :  %.2lf\n", (*p).number, (*p).name, (*p).grade);
}

struct date{
	int month;
	int day;
	int year;
};
struct student{
	int number;
	char name[20];
	double grade;
	struct date *dob;
};
int main(){
	struct date d = {7,10,2001};
	struct student s = {200,"홍은빈",5.0};
	s.dob = &d;
	
	printf("학번 : %d\n",s.number); 
	printf("이름 : %s\n",s.name); 
	printf("학점 : %.2lf\n",s.grade);
	printf("생년월일 : %d년 %d월 %d일 \n",s.dob->year,s.dob->month,s.dob->day); 
	printf("생년월일 : %d년 %d월 %d일 \n",(*s.dob).year,s.dob->month,s.dob->day);   
}

#include<stdio.h>
struct student{
	int number;
	char name[10];
	double grade;
	struct student *next;
};
int main(){
	struct student s1 = {200,"홍은빈",5.0,NULL};
	struct student s2 = {201," 홍길동",4.0,NULL};	 
	
	printf("%d %d %d",&s1.number,&s1.name,&s1.grade);
	
	struct student *first = NULL; 
	struct student *current = NULL;
	
	first = &s1;
	s1.next = &s2;
	s2.next = NULL;//연결 리스트가 끝났다고 마지막에 NULL넣어서 알려줌 
	first->next = &s2;
	(*first).next = &s2;
}
//배열의 장점 - 탐색 속도가 빠르다.(첨자 사용 용이) 사용자가 사용하기 쉽다. 
//연결 리스트 장점 - 삽입과 삭제가 쉽다. 

#include<stdio.h>
struct student{
	int number;
	char name[10];
	double grade;
	struct student *next;
};
int main(){
	struct student s1 = {200,"홍은빈",5.0,NULL};
	struct student s2 = {201," 홍길동",4.0,NULL};	 
	
	printf("%d %d %d",&s1.number,&s1.name,&s1.grade);
	
	struct student *first = NULL; 
	struct student *current = NULL;
	
	first = &s1;
	s2.next = NULL;
	first->next = &s2;
//	(*first).next = &s2;
	
	current = first;//처음 시작이라고 알려줌 
	while(current != NULL){
		printf("학생번호 = %d, 이름 : %s, 성적 : %lf\n",current->number,current->name,current->grade);
		current = current->next;//current 에 s1.next안에 있는 s2의 주소를 넘겨줌 
		printf("학생번호 = %d, 이름 : %s, 성적 : %lf\n",current->number,current->name,current->grade);
	}
	 
}
//함수 매개변수 - 배열(원본)(포인터 사용 x 원본 사용하기 때문에) -> return 별로 필요 x 
//				- 구조체(복사본) -> 원본 사용하고 싶으면 포인트 (메모리 낭비와 시간 절약하기 위해 원본 사용)
//				- 변수(복사본) - 원본 사용하고 싶으면 포인트 
//				- 구조체 안에 있는 배열은 복사 개념이다!!!!!! 완전 중요!!!!!!!! 
