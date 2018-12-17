#include<stdio.h>

int main(){
	
	int num[7][7], i, j ,a = 1;
	for(i = 0; i < 7; i++){
		for(j = 0; j <= i; j++){
			num[i][j] = a;
			printf("%5d",num[i][j]);
			a++;
		}
		printf("\n");
		a += 7-(i+1);
	}
} 

#include<stdio.h>
#include<string.h>
int main(){
	char name[10][20] = {"kim", "lee", "sin","jo","kim2","chae","jin","back","so","chol"};
	printf("배열 초기화 : \n");
	int i,j;
	char temp[10];
	for( i = 0 ; i < 10; i++){
		for(j = 0 ; j < i; j++){
			if(strcmp(name[i],name[j]) < 0){
				strcpy(temp,name[i]);
				strcpy(name[i],name[j]);
				strcpy(name[j],temp);
			}
		}
	}
//	선생님 코드 
//	for(i = 0; i < 9; i++){
//		for(j = 0; j < 9-i; j++){
//			if(strmp(name[j],name[j+1]) > 0){
//				strcpy(temp,name[j]);
//				strcpy(name[j],name[j+1]);
//				strcpy(name[j+1],temp);
//			}
//		}
//	}
	for(i = 0 ; i < 10; i++){
		printf("%s\n",name[i]);
	}
}

#include<stdio.h>
#include<string.h>
#define STUDENT 4
#define SUBJECT 5
void heading();

int main(){
	char name[STUDENT][20] = {"홍길동","성춘향","진달래","개나리"};
	int score[STUDENT][SUBJECT+2] = {{78, 90, 34, 46,80},{98,74,84,76,72},{76,48,34,72,89},{61,91,67,88,83}};
	
	int i, j, sum=0, row, col;
	
	row = sizeof(score)/sizeof(score[0]);
	col = sizeof(score[0])/sizeof(score[0][0]);
	
	for(i = 0; i < row; i++){
		for(j = 0; j< col-2; j++){
			score[i][col-2] += score[i][j];
		}
		score[i][col-1] = score[i][col-2]/(col-2);
	}
	heading();
	for(i = 0; i < row; i++){
		printf("%5s, ",name[i]);
		for(j = 0; j < col; j++){
			printf("%3d, ",score[i][j]);
		}
		printf("\n");
	}
}
void heading(){
	printf("==========================\n");
	printf("성적표\n");
	printf("==========================\n");
}
