	#include<stdio.h>
#include<string.h>
int main(){	
	int score[100] = {57,87,64,86,97,78,61,81,73,37,54}, i, sum = 0, cn = 0;
	int *ptr; 
	ptr = score;
	printf("학생들의 점수 : ");
	while(*ptr){
		cn++;
		sum += *ptr++;
		printf("%d, ",*ptr++);
		*ptr--;
	}
	printf("\n인원수 : %d\n",cn);
	printf("합 : %d , 평균 : %.2f",sum, (float)sum/cn);
}
