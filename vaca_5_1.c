#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#define X_MAX 79 //가로 (열) 방향의 최대값
#define Y_MAX 24 //세로 (행) 방향의 최대값
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b);
void gotoxy(int x, int y);

int main() {
	char key;
	int x = 10, y = 5;
	do{
		gotoxy(x, y);
		printf("A");
		key = _getch();
		system("cls");
	//	printf("\b  ");//
		do{
			move_arrow_key(key, &x, &y, X_MAX, Y_MAX);
		gotoxy(x, y);
		printf("A");
		Sleep(50); //이동 지연 시간
	} while (!_kbhit()); //눌려져 있으면 1 리턴 없으면 0 리턴
	} while (key != 27);
	return 0;
}
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b){
	switch (key)
	{
	case 72: //위쪽(상) 방향의 화살표 키 입력
		*y1 = *y1 - 1;
		if (*y1 < 1) *y1 = 1; //y좌표의 최소값
			break;
	case 75:
		*x1 = *x1 - 1; //왼쪽(좌) 방향의 화살표 키 입력
		if (*x1 < 1)  *x1 = 1;//y좌표의 최소값
			break;
	case 77:
		*x1 = *x1 + 1;  //오른쪽(우) 방향의 화살표 키 입력
		if (*x1 > x_b) *x1 = x_b;//y좌표의 최대값
			break;
	case 80 :
		*y1 = *y1 +1; //아래쪽(하) 방향의 화살표 키 입력
		if (*y1 > y_b)  *y1 = y_b;//y좌표의 최대값
			break;
	case 71 : //좌상 방향키(7:home)
		*x1 = *x1 - 1;
		*y1 = *y1 - 1;
		break;
	case 73: //우상 방향 키 (9:pgUp)
		*x1 = *x1 + 1;
		*y1 = *y1 - 1;
		break;
	case 79: //좌하 방향 키 ( 1 : End)
		*x1 = *x1 - 1;
		*y1 = *y1 + 1;
		break;
	case 81: //우하 방향 키 ( 3 : PgDn)
		*x1 = *x1 + 1;
		*y1 = *y1 + 1;
		break;
	}
}
void gotoxy(int x, int y){
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void draw_basic_square(int size);

int main(void){
	int n;

	printf("정사각형 그리기\n\n");
	printf("정사각형의 크기(최대 37)를\n");
	printf("입력하고 Enter> ");
	scanf("%d", &n);
	draw_basic_square(n);
	return 0;
}

void draw_basic_square(int size){
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];
	
	for (i = 1; i < 7; i++){	b[i] = 0xa0 + i; }
	printf("%c%c", a, b[3]);

	for (i = 0; i < size; i++)
	{
		printf("%c%c", a, b[1]);
	}

		printf("%c%c", a, b[4]);
		printf("\n");
	
	for (i = 0; i < size; i++) {
		printf("%c%c", a, b[2]);

		for (j = 0; j < size; j++) {	printf(" ");	
		} //기호는 다 2바이트

		printf("%c%c", a, b[2]);
		printf("\n");		
	}

	printf("%c%c", a, b[6]);

	for (i = 0; i < size; i++){	printf("%c%c", a, b[1]); }

	printf("%c%c", a, b[5]);
	printf("\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void) {
	int i, j;
	for (j = 1; j <= 9; j++) {
		system("cls");
		for (i = 1; i <= 9; i++) {
			printf("%d * %d = %d\n", j, i, j * i);
		}
			printf("아무키나 누르시오.\n");
			_getch();
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void) {
	int i, j;
	for (j = 1; j <= 9; j++) {
		system("cls");
		for (i = 1; i <= 9; i++) {
			printf("%d * %d = %d\n", j, i, j * i);
		}
			printf("아무키나 누르시오.\n");
			_getch();
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void) {
	int i, j;
	for (j = 1; j <= 9; j++) {
		system("cls");
		for (i = 1; i <= 9; i++) {
			printf("%d * %d = %d\n", j, i, j * i);
		}
			printf("아무키나 누르시오.\n");
			_getch();
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void) {
	int i, j;
	for (j = 1; j <= 9; j++) {
		system("cls");
		for (i = 1; i <= 9; i++) {
			printf("%d * %d = %d\n", j, i, j * i);
		}
			printf("아무키나 누르시오.\n");
			_getch();
	}
	return 0;
}
