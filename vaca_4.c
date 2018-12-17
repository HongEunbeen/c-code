#include<stdio.h>//standared input, output의 약자 
#include<stdlib.h> 
int main(){
	int *a;
	int b,sum = 0,i;
	printf("정수의 개수 : "); 
	scanf("%d",&b);
	a = (int *)malloc(sizeof(int));
	for(i = 0; i < b; i++){
		printf("양의 정수 입력 : ");
		scanf("%d",&a[i]);
		sum += a[i];
	}
	printf("합은 %d이다.",sum);
}

