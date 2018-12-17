#include<stdio.h>
struct student{
	int number;
	char name[20];
	double grade;
};
int main(){	
	struct student list[3];
	int i;
	for(i = 0; i< 3; i++){
		scanf("%d",&list[i].number);
		fflush(stdin); 
		scanf("%s",list[i].name);
		fflush(stdin);
		scanf("%lf",&list[i].grade);
		fflush(stdin);
	}
	for(i = 0; i< 3; i++){
		printf("학번 : %d,  이름 :  %s,  학점 :  %.2lf",list[i].number,list[i].name, list[i].grade);
	}
}
