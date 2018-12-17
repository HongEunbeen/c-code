#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
void gotoxy(int x, int y);
void shuffle_number(int sit_number[], int total);
void seat_arrangement(int cols,int row);
void draw_check02(int c, int );
int main(){
	int cols, row;
	printf("행을 입력하세요");
	scanf("%d",&cols);
	printf("열을 입력하세요");
	scanf("%d",&row);
	fflush(stdin);
	gotoxy(0,7);
	draw_check02(cols, row);
	seat_arrangement(cols, row);	
} 
void seat_arrangement(int cols,int row){
	int total,i,j;
	total = cols * row;
	int sit_number[total];
	for(i = 1; i <= total; i++){
		sit_number[i-1] = i; 
	}
	shuffle_number(sit_number,total);
	gotoxy(1,7);
	int count = 0;
	for(i = 0; i < cols; i++){
		for(j = 0; j < row; j++){
			gotoxy((j*4)+2, 8+i*2);
			printf("%d",sit_number[count]);
			count++;
		}
	}
	gotoxy(20,20);
}
void shuffle_number(int sit_number[], int total){
	int i, j,temp;
	srand(time(NULL));
	for(i = 0; i < total; i++){
		for(j = 0 ; j < i; j++){
			temp = rand() % total + 1;
			if(sit_number[i] == temp){
				sit_number[i] = sit_number[j];
				sit_number[j] = temp;
			}
		}
	}

}
void gotoxy(int x, int y){
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void draw_check02(int clos, int row){
	int i,j;
	unsigned char a = 0xa6;
	unsigned char b[12];
	for(i = 1; i < 12; i++){
		b[i] = 0xa0+i;
	}
	printf("%c%c", a, b[3]);
	for(i = 1; i < row; i++){
		printf("%c%c",a,b[1]);
		printf("%c%c",a,b[1]);
		printf("%c%c",a,b[1]);
		printf("%c%c", a, b[8]);
	}
	printf("%c%c",a,b[1]);
	printf("%c%c",a,b[1]);
	printf("%c%c",a,b[1]);
	printf("%c%c", a, b[4]);
	printf("\n");
	for(i = 1; i < clos; i++){
		printf("%c%c", a, b[2]);
		for(j = 1; j < row+1; j++){
			printf("   ");
			printf("%c%c",a,b[2]);
		}
		printf("\n");
		printf("%c%c",a,b[7]);
		for(j = 1; j < row; j++){
			printf("%c%c",a,b[1]);
			printf("%c%c",a,b[1]);
			printf("%c%c",a,b[1]);
			printf("%c%c", a, b[11]);
		}
		printf("%c%c",a,b[1]);
		printf("%c%c",a,b[1]);
		printf("%c%c",a,b[1]);
		printf("%c%c", a, b[9]);
		printf("\n");
	}
	printf("%c%c", a, b[2]);
	for(i = 1; i < row+1; i++){
		printf("   ");
		printf("%c%c",a,b[2]);
	}
	printf("\n");
	printf("%c%c", a, b[6]);
	for(i = 1; i < row; i++){
		printf("%c%c",a,b[1]);
		printf("%c%c",a,b[1]);
		printf("%c%c",a,b[1]);
		printf("%c%c", a, b[10]);
	}
	printf("%c%c",a,b[1]);
	printf("%c%c",a,b[1]);
	printf("%c%c",a,b[1]);
	printf("%c%c", a, b[5]);
	printf("\n");
}
