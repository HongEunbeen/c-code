#include<stdio.h>//standared input, output�� ���� 
#include<stdlib.h> 
int main(){
	int *a;
	int b,sum = 0,i;
	printf("������ ���� : "); 
	scanf("%d",&b);
	a = (int *)malloc(sizeof(int));
	for(i = 0; i < b; i++){
		printf("���� ���� �Է� : ");
		scanf("%d",&a[i]);
		sum += a[i];
	}
	printf("���� %d�̴�.",sum);
}

