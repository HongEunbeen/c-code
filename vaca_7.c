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
	
	for(i = 0; i < 7; i++){
		for(j = 0 ; j < 7; j++){
			printf("%5d",num[i][j]);
		}
		printf("\n");
	}
} 
