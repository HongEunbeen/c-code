#include<stdio.h>
#include<string.h>
#include<time.h>
int main(){
	int test[5][3], i, j ,ans, score, sum;
	srand(time(0));
	for(i = 0; i < 5; i++){
		test[i][0] = rand()%90 + 10;
		test[i][1] = rand()%90 + 10;
		printf("%d��° ���� : ",i+1);
		printf("%d + %d = ",test[i][0],test[i][1] );
		scanf("%d",&ans);
		test[i][2] = ans;
	}
	printf("\n\n");
	score = 0;
	for(i = 0; i < 5; i++){
		printf("%2d�� : %3d + %3d = %3d",i+1,test[i][0],test[i][1],test[i][2]);
		sum = test[i][0] + test[i][1];
		if(sum == test[i][2]){
			score++;
			printf("(o)\n");			
		}
		else printf("(x) ---> %3d\n",sum);
	}
	printf("\n %d�� �¾ҽ��ϴ�.\n",score);
}
