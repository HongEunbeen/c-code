#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

int calc_frequency(int octave, int inx);
void practice_piano();
void dispaly_manual();
void gotoxy(int x, int y);
void draw_check02(int clos, int row);
void display_piano_keyboard();
void touch_keyboard(code);
void face();

int main(){
	dispaly_manual();
	practice_piano();
	gotoxy(30,30);
}
void display_piano_keyboard(){
	int i;
	char code[8][4] = {"도","레","미","파","솔","라","시","도"};
	for(i = 0; i < 8; i++){
		gotoxy(2+i*4,5);
		printf("%2d",i+1);
	}
	for(i = 0 ; i < 8; i++){
		gotoxy(2+i*4,7);
		printf("%s",code[i]);
	}
}
void dispaly_manual(){
	printf("키보드의 숫자를 누르면 \n");
	printf("해당 건반에 음이 표시되고, \n");
	printf("해당 음이 스피커로 출력됩니다. \n");
	printf("프로그램 종료는 ESC키 입니다. \n");
}
void practice_piano(){
	int index[] = {0,2,4,5,7,9,11,12};//도레미파솔라시도 
	int i;
	int code;
	int freq[8];
	for(i = 0; i < 8; i++){
		freq[i] = calc_frequency(4, index[i]);
	}
	draw_check02(2,8);
	display_piano_keyboard();
	do{
		code = getch();
		if('1' <= code && code <= '8'){
			code -= 49; 
			touch_keyboard(code);
			Beep(freq[code],300);//300-지연시간 
			display_piano_keyboard();
		}
		else if(code = '0'){
			int face[] = {7,7,7,7,7,2,3,4,5,5,5,6,7,6,7,6,5,4,2,3,3,3,4,4,4,2,4,4,7,5,6,7,7,7,6,7};
			for(i = 0 ; i < sizeof(face)/sizeof(int); i++){
				touch_keyboard(face[i]);
				Beep(freq[face[i]],300);//300-지연시간 
				display_piano_keyboard();
		}
	}
	}while(code != 27);
}
void touch_keyboard(int code){
	//누른 자리에 표시 기능 
	gotoxy(2+code*4,7);
	printf("%c%c",0xa1, 0xe3);
	
	
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
