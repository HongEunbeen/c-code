#include<stdio.h>
int main(){	
	char str[30] = "C language is easy";
	int i; 
	while(str[i] != '\0') i++;
	printf("%d",i);
}

