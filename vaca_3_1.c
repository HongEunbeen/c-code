#include<stdio.h>
struct student{
	int number;
	char name[20];
	double grade;
};
int main(){
	struct student s = {200,"ȫ�浿",5.0};
	
	struct student *p;//����ü�� ����Ű�� ������
	p = &s; 
	
	printf("�й� : %d, �̸� :  %s, ���� :  %.2lf\n",s.number, s.name, s.grade);
	printf("�й� : %d, �̸� :  %s, ���� :  %.2lf\n",p->number, p->name, p->grade);
	printf("�й� : %d, �̸� :  %s, ���� :  %.2lf\n", (*p).number, (*p).name, (*p).grade);
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
	struct student s = {200,"ȫ����",5.0};
	s.dob = &d;
	
	printf("�й� : %d\n",s.number); 
	printf("�̸� : %s\n",s.name); 
	printf("���� : %.2lf\n",s.grade);
	printf("������� : %d�� %d�� %d�� \n",s.dob->year,s.dob->month,s.dob->day); 
	printf("������� : %d�� %d�� %d�� \n",(*s.dob).year,s.dob->month,s.dob->day);   
}

#include<stdio.h>
struct student{
	int number;
	char name[10];
	double grade;
	struct student *next;
};
int main(){
	struct student s1 = {200,"ȫ����",5.0,NULL};
	struct student s2 = {201," ȫ�浿",4.0,NULL};	 
	
	printf("%d %d %d",&s1.number,&s1.name,&s1.grade);
	
	struct student *first = NULL; 
	struct student *current = NULL;
	
	first = &s1;
	s1.next = &s2;
	s2.next = NULL;//���� ����Ʈ�� �����ٰ� �������� NULL�־ �˷��� 
	first->next = &s2;
	(*first).next = &s2;
}
//�迭�� ���� - Ž�� �ӵ��� ������.(÷�� ��� ����) ����ڰ� ����ϱ� ����. 
//���� ����Ʈ ���� - ���԰� ������ ����. 

#include<stdio.h>
struct student{
	int number;
	char name[10];
	double grade;
	struct student *next;
};
int main(){
	struct student s1 = {200,"ȫ����",5.0,NULL};
	struct student s2 = {201," ȫ�浿",4.0,NULL};	 
	
	printf("%d %d %d",&s1.number,&s1.name,&s1.grade);
	
	struct student *first = NULL; 
	struct student *current = NULL;
	
	first = &s1;
	s2.next = NULL;
	first->next = &s2;
//	(*first).next = &s2;
	
	current = first;//ó�� �����̶�� �˷��� 
	while(current != NULL){
		printf("�л���ȣ = %d, �̸� : %s, ���� : %lf\n",current->number,current->name,current->grade);
		current = current->next;//current �� s1.next�ȿ� �ִ� s2�� �ּҸ� �Ѱ��� 
		printf("�л���ȣ = %d, �̸� : %s, ���� : %lf\n",current->number,current->name,current->grade);
	}
	 
}
//�Լ� �Ű����� - �迭(����)(������ ��� x ���� ����ϱ� ������) -> return ���� �ʿ� x 
//				- ����ü(���纻) -> ���� ����ϰ� ������ ����Ʈ (�޸� ����� �ð� �����ϱ� ���� ���� ���)
//				- ����(���纻) - ���� ����ϰ� ������ ����Ʈ 
//				- ����ü �ȿ� �ִ� �迭�� ���� �����̴�!!!!!! ���� �߿�!!!!!!!! 
