#include <stdio.h>

int main(){
	int n,m,n_a[100],i,j,x[100],y[100];
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&n_a[i]);
	}
	scanf("%d",&m);
	for(i= 0; i < m; i++){
		scanf("%d %d",&x[i],&y[i]);
	}
	for(i= 0; i < m; i++){
		if(x[i] == y[i]){
			printf("%d\n",n_a[n/2]);
		}
		else if(x[i] == 0  y[i]== 0){
			printf("0");
		}
		else if(x[i] > y[i]){
			int re = x[i] - y[i];
			printf("%d\n",n_a[(n/2) + re]);
		}
		else if(x[i] < y[i]){
			int ree = y[i] - x[i];
			printf("%d\n",n_a[(n/2) - ree]);
		}
		
	}
}
//첫 번째 줄에 케잌의 영역수를 나타내는 자연수 n이 주어진다. 

//두 번째 줄에 영역의 가치를 나타내는 값 n개가 공백으로 구분되어 입력된다. 

//세 번째 줄에 질문의 수 m이 입력된다. 

//다음 줄 부터 m줄에 걸쳐서 한 줄에 하나씩 x, y의 값이 공백으로 구분되어 입력된다. 
