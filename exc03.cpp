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
//ù ��° �ٿ� �ɟ��� �������� ��Ÿ���� �ڿ��� n�� �־�����. 

//�� ��° �ٿ� ������ ��ġ�� ��Ÿ���� �� n���� �������� ���еǾ� �Էµȴ�. 

//�� ��° �ٿ� ������ �� m�� �Էµȴ�. 

//���� �� ���� m�ٿ� ���ļ� �� �ٿ� �ϳ��� x, y�� ���� �������� ���еǾ� �Էµȴ�. 
