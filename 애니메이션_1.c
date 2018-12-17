#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
void intro_game();
void gotoxy(int x, int y);
void display(int count, int r_count);
void game_control(int *r_c,int rnd,int *target);
void horizontal_slide(int x, int y, char c2[]);
int calc_frequency(int octave, int inx);

int main(){
	int count = 0;
	int r_count = 0;
	int rnd; // 목표물의 위치를 저장하는 값 
	char *target = "○";//바꾸기 x 주소의 개념을 가지고 있어서 포인터로 활용 
	srand(time(NULL));//start rand함수 사용하지 않으면 rand에서 항상 같은 값이 나온다. (rand를 초기화 해준다고 생각하면 됌) 
	intro_game();
	getch(); 
	int i;
	do{
		system("cls");
		draw_rectangle(20,20);
		rnd = rand() % 19 + 1;// 0~34 // 4~38 // 목표물의 위치
		gotoxy(rnd,2);
		printf("%s",target);
		Sleep(100); 
		count++;
		display(r_count,count);//총 실행 횟수와 맞은 갯수 출력 
		game_control(&r_count,rnd,target); 
		
		gotoxy(30,30);
	}while(count < 10);
	
	
}
void intro_game(){
	printf("말타며 화살쏘기\n\n");
	printf("말을 타고 이동하면서\n");
	printf("목표물(○)을 맞추는 게임입니다.\n");
	printf("화살은 스페이스키로 발사합니다.\n\n");
	printf("아무키나 누르면 시작합니다.\n"); 
}
void gotoxy(int x, int y){
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void draw_rectangle(int x, int y){
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];
	for (i = 1; i < 7; i++){
		b[i] = 0xa0 + i; 
	}
	printf("%c%c", a, b[3]);

	for (i = 0; i < x; i++)
	{
		printf("%c%c", a, b[1]);
	}
	printf("%c%c", a, b[4]);
	printf("\n");
	for (i = 0; i < y; i++) {
		printf("%c%c", a, b[2]);
		for (j = 0; j < x; j++) {
			printf(" ");	
		} //기호는 다 2바이트
		printf("%c%c", a, b[2]);
		printf("\n");		
	}
	printf("%c%c", a, b[6]);
	for (i = 0; i < x; i++){
		printf("%c%c", a, b[1]);
	}
	printf("%c%c", a, b[5]);
	printf("\n");
}
void horizontal_slide(int x, int y, char c2[]){
	gotoxy(x,y);
	printf("%s",c2);
	Sleep(100);
	printf("\b ");
}
void horizontal_slide2(int x, int y, char c2[]){
	gotoxy(x,y);
	printf("%s",c2);
	Sleep(100);
	printf("\b ");
}
void display(int r_count, int count){
	gotoxy(35,5);
	printf("총 실행 횟수 : %d",count);
	printf("맞은 횟수 : %d",r_count);
}
void game_control(int *r_c,int rnd, int *target){
	char *horse = "▲";//말 
	int i = 0, k = 0, move = 0;
	char chr;
	do{
		//말을 좌우로 이동시킴 
		rnd += move;
		i += k; 
		if(rnd > 14){
			move -= 1;
		}
		else if(rnd < 2){
			move += 1;
		}
		if(i > 14){
			k -= 1;
		}
		else if(i < 2){
			k += 1;
		}
		horizontal_slide(i + 2, 20, horse);
		horizontal_slide2(rnd,2,target);
	}while(!_kbhit());
	chr = getch();
	int y = 20; //y값 현재 위 
	if(chr == 32 ) {
		while(y > 2){
			y -= 1;
			gotoxy(i+1, y);//i+1은 내가 스페이스를 누른 값 
			printf("↑");
			Sleep(100);
			printf("\b ");
		}
		if((i <= (rnd + 1)) && (i >= (rnd - 1))){
			int sound;
			gotoxy(rnd,2);
			printf("☆");
			sound = calc_frequency(4,0);//정해져 있는 함수 
			Beep(sound, 300);
			gotoxy(46,8);
			printf("맞았습니다");
			Sleep(100);
			*r_c = *r_c+1;
		}
		gotoxy(1,24);
		printf("아무키나 누르면 다음 진행");
		getch(); 
	}
	//누른 키가 스페이스바 키이면 화살을 발사하고 화살을 화면에 연속적으로 표시. 목표물이 맞았늕 확인 맞았느면 갯수를 증가 
	
}
int calc_frequency(int octave, int inx){ //사용자는 octave만 건들일 수 있담!!!! 
	double do_scale = 32.7032;
	double ratio = (double)pow(2.,1/12.),temp;
	int i ;
	temp = do_scale*(double)pow(2,octave-1);
	for(i = 0 ; i < inx; i++){
		temp = (int )(temp + 0.5);
		temp *= ratio;
	}
	return (int)temp;
} 

