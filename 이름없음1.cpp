//ù° �ٿ� ������ ���� N�� �׷��� �� M�� �־�����.

//��° �ٿ��� �� ������ ������ ���ڰ� ���ʺ��� ���ʷ� �־�����.

//N�� 300 ������ �ڿ���, M�� N������ �ڿ����̸�, ������ ������ ���ڴ� 100 ������ �ڿ����̴�.
#include<stdio.h>
int ball;
int main(){
	int g,i;
	scanf("%d %d",&ball,&g);
	int ballnum[ball];
	for(i = 0; i < ball; i++){
		scanf("%d",ballnum[i]);
	}
	check(ballnum);
	
	
}
int check(int *ballnum){
	int i;
	int max = ballnum[i]+ballnum[i+1];
	for(i = 0; i < ball; i+2){
		if(ballnum[i]+ballnum[i+1] > max){
			max = ballnum[i]+ballnum[i+1];
		}
	}
}
