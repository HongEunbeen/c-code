#include<stdio.h>//standared input, output�� ���� 
#include<stdlib.h> 
#include<string.h>

typedef struct node{
	char title[50];
	int year;
	struct node *link;
}NODE;//�ϳ��� ���� ����Ʈ ���� node��� �θ���. 
int main(){
	NODE *p;
	NODE *list = NULL;
	NODE *prev;
	NODE *next;//�����޸𸮸� ������ ���� ������ 
	char buffer[50];
	int year;
	//���� ����Ʈ�� ������ �Է��Ѵ�. 
	while(1){
		printf("å�� ������ �Է��Ͻÿ�.");
		gets(buffer);
		if(buffer[0] == '\0'){
			break;
		}
		p =	(NODE*)malloc(sizeof(NODE));// p�� ����ؼ� ���� 
		strcpy(p->title,buffer);
		
		printf("���� ������ �Է��Ͻÿ�.");
		gets(buffer);
		p->year = atoi(buffer); //���ڿ� -> ���ڷ� ��ȯ
		//������ �ִ� ���Ḯ��Ʈ �˰��� 30~41 ������ �ڵ� 
		if(list == NULL){
			list = p;
		}
		else {
			prev->link = p;//prev ���� �ּҸ� ����ϰ� �ϱ� ���� prev����  
		}
		p->link = NULL;//���̶�� �˸��� ���� NULL ����  
		prev = p;//p�� �ٽ� �ּҸ� ���� ���� ���� �ε忡�� �˷��־�� �� 
	}	
	printf("\n");
	
	p = list;
	while(p != NULL){
		printf("å ���� : %s\n���ǳ⵵ : %d\n",p->title,p->year);
		p = p->link;
	}
	
	//�����޸� �Ҵ��Ѱ� ���������� ���ؼ� ó������ �ٽ� �����߉� 
	p = list;//p�� �ٽ� �� ó������ ���ƿ� 
	while(p != null){//������ ������� �� 
		next = p->link;//���� �ּҸ� ���� ������ ���� ���� �ּҸ� ���ֱ�	
		free(p);//������ ����� 
		p = next;//���� �ּҸ� �ٽ� ���� 
	}
	
}
