	#include<stdio.h>
#include<string.h>
int main(){	
	int score[100] = {57,87,64,86,97,78,61,81,73,37,54}, i, sum = 0, cn = 0;
	int *ptr; 
	ptr = score;
	printf("�л����� ���� : ");
	while(*ptr){
		cn++;
		sum += *ptr++;
		printf("%d, ",*ptr++);
		*ptr--;
	}
	printf("\n�ο��� : %d\n",cn);
	printf("�� : %d , ��� : %.2f",sum, (float)sum/cn);
}
