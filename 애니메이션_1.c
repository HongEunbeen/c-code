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
	int rnd; // ��ǥ���� ��ġ�� �����ϴ� �� 
	char *target = "��";//�ٲٱ� x �ּ��� ������ ������ �־ �����ͷ� Ȱ�� 
	srand(time(NULL));//start rand�Լ� ������� ������ rand���� �׻� ���� ���� ���´�. (rand�� �ʱ�ȭ ���شٰ� �����ϸ� ��) 
	intro_game();
	getch(); 
	int i;
	do{
		system("cls");
		draw_rectangle(20,20);
		rnd = rand() % 19 + 1;// 0~34 // 4~38 // ��ǥ���� ��ġ
		gotoxy(rnd,2);
		printf("%s",target);
		Sleep(100); 
		count++;
		display(r_count,count);//�� ���� Ƚ���� ���� ���� ��� 
		game_control(&r_count,rnd,target); 
		
		gotoxy(30,30);
	}while(count < 10);
	
	
}
void intro_game(){
	printf("��Ÿ�� ȭ����\n\n");
	printf("���� Ÿ�� �̵��ϸ鼭\n");
	printf("��ǥ��(��)�� ���ߴ� �����Դϴ�.\n");
	printf("ȭ���� �����̽�Ű�� �߻��մϴ�.\n\n");
	printf("�ƹ�Ű�� ������ �����մϴ�.\n"); 
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
		} //��ȣ�� �� 2����Ʈ
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
	printf("�� ���� Ƚ�� : %d",count);
	printf("���� Ƚ�� : %d",r_count);
}
void game_control(int *r_c,int rnd, int *target){
	char *horse = "��";//�� 
	int i = 0, k = 0, move = 0;
	char chr;
	do{
		//���� �¿�� �̵���Ŵ 
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
	int y = 20; //y�� ���� �� 
	if(chr == 32 ) {
		while(y > 2){
			y -= 1;
			gotoxy(i+1, y);//i+1�� ���� �����̽��� ���� �� 
			printf("��");
			Sleep(100);
			printf("\b ");
		}
		if((i <= (rnd + 1)) && (i >= (rnd - 1))){
			int sound;
			gotoxy(rnd,2);
			printf("��");
			sound = calc_frequency(4,0);//������ �ִ� �Լ� 
			Beep(sound, 300);
			gotoxy(46,8);
			printf("�¾ҽ��ϴ�");
			Sleep(100);
			*r_c = *r_c+1;
		}
		gotoxy(1,24);
		printf("�ƹ�Ű�� ������ ���� ����");
		getch(); 
	}
	//���� Ű�� �����̽��� Ű�̸� ȭ���� �߻��ϰ� ȭ���� ȭ�鿡 ���������� ǥ��. ��ǥ���� �¾҈d Ȯ�� �¾Ҵ��� ������ ���� 
	
}
int calc_frequency(int octave, int inx){ //����ڴ� octave�� �ǵ��� �� �ִ�!!!! 
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

