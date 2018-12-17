#include<stdio.h>
#include<windows.h>
void gotoxy(int w, int y);
int main(){
	int x = 0, y = 1, temp = 2, count =0; 
	while(count < 3){
		x += temp;
		if(x>20)
		temp = -2;
		if(x<2){
			temp = 2;
			count++;
		}
		printf("\b");
		gotoxy(x,y);
		printf("▣");
		Sleep(50);//움직이는 속도 조절 
	}
}
void gotoxy(int x, int y){
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
