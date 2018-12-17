//첫째 줄에 구슬의 개수 N과 그룹의 수 M이 주어진다.

//둘째 줄에는 각 구슬이 적혀진 숫자가 왼쪽부터 차례로 주어진다.

//N은 300 이하의 자연수, M은 N이하의 자연수이며, 구슬에 적혀진 숫자는 100 이하의 자연수이다.
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
