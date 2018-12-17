#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
void gotoxy(int x, int y){
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void draw_check01(int c, int r){
	int i,j;
	unsigned char a = 0xa6;
	unsigned char b[12];
	for(i = 1; i < 12; i++){
		b[i] = 0xa0+i;
	}
	printf("%c%c", a, b[3]);
	for(i = 1; i < c; i++){
		printf("%c%c",a,b[1]);
		printf("%c%c",a,b[1]);
		printf("%c%c", a, b[8]);
	}
	printf("%c%c",a,b[1]);
	printf("%c%c",a,b[1]);
	printf("%c%c", a, b[4]);
	printf("\n");
	for(i = 1; i < r; i++){
		printf("%c%c", a, b[2]);
		for(j = 1; j < c+1; j++){
			printf("  ");
			printf("%c%c",a,b[2]);
		}
		printf("\n");
		printf("%c%c",a,b[7]);
		for(j = 1; j < c; j++){
			printf("%c%c",a,b[1]);
			printf("%c%c",a,b[1]);
			printf("%c%c", a, b[11]);
		}
		printf("%c%c",a,b[1]);
		printf("%c%c",a,b[1]);
		printf("%c%c", a, b[9]);
		printf("\n");
	}
	printf("%c%c", a, b[2]);
	for(i = 1; i < c+1; i++){
		printf("  ");
		printf("%c%c",a,b[2]);
	}
	printf("\n");
	printf("%c%c", a, b[6]);
	for(i = 1; i < c; i++){
		printf("%c%c",a,b[1]);
		printf("%c%c",a,b[1]);
		printf("%c%c", a, b[10]);
	}
	printf("%c%c",a,b[1]);
	printf("%c%c",a,b[1]);
	printf("%c%c", a, b[5]);
	printf("\n");
}
int main(){
	int row, column;
	printf("바둑판 그리기\n\n");
	printf("가로 세로의 길이를 space로 \n");
	printf("분리하여 입력하고 Enter>");
	scanf("%d %d",&column,&row);
	system("cls");
	draw_check01(column, row); 
	gotoxy(2,1);
	printf("A");
	gotoxy(11,1);
	printf("A");
	gotoxy(1,20);
	
} 
