#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#define X_MAX 79 //���� (��) ������ �ִ밪
#define Y_MAX 24 //���� (��) ������ �ִ밪
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
		Sleep(50); //�̵� ���� �ð�
	} while (!_kbhit()); //������ ������ 1 ���� ������ 0 ����
	} while (key != 27);
	return 0;
}
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b){
	switch (key)
	{
	case 72: //����(��) ������ ȭ��ǥ Ű �Է�
		*y1 = *y1 - 1;
		if (*y1 < 1) *y1 = 1; //y��ǥ�� �ּҰ�
			break;
	case 75:
		*x1 = *x1 - 1; //����(��) ������ ȭ��ǥ Ű �Է�
		if (*x1 < 1)  *x1 = 1;//y��ǥ�� �ּҰ�
			break;
	case 77:
		*x1 = *x1 + 1;  //������(��) ������ ȭ��ǥ Ű �Է�
		if (*x1 > x_b) *x1 = x_b;//y��ǥ�� �ִ밪
			break;
	case 80 :
		*y1 = *y1 +1; //�Ʒ���(��) ������ ȭ��ǥ Ű �Է�
		if (*y1 > y_b)  *y1 = y_b;//y��ǥ�� �ִ밪
			break;
	case 71 : //�»� ����Ű(7:home)
		*x1 = *x1 - 1;
		*y1 = *y1 - 1;
		break;
	case 73: //��� ���� Ű (9:pgUp)
		*x1 = *x1 + 1;
		*y1 = *y1 - 1;
		break;
	case 79: //���� ���� Ű ( 1 : End)
		*x1 = *x1 - 1;
		*y1 = *y1 + 1;
		break;
	case 81: //���� ���� Ű ( 3 : PgDn)
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

	printf("���簢�� �׸���\n\n");
	printf("���簢���� ũ��(�ִ� 37)��\n");
	printf("�Է��ϰ� Enter> ");
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
		} //��ȣ�� �� 2����Ʈ

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
			printf("�ƹ�Ű�� �����ÿ�.\n");
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
			printf("�ƹ�Ű�� �����ÿ�.\n");
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
			printf("�ƹ�Ű�� �����ÿ�.\n");
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
			printf("�ƹ�Ű�� �����ÿ�.\n");
			_getch();
	}
	return 0;
}
