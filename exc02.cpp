#include<iostream>
#include<string>

using namespace std;

//int main(){
//	string name;
//	int score;
//	cout<<"�̸� �Է� : ";
//	cin>>name;
//	cout<<"���� �Է� : ";
//	cin>>score;
//	cout<<name<<"���� ������ "<<score<<"���Դϴ�."<<endl; 
//}
int main(){
	int arr[2][3] = {{1,2,3},{4,5,6}};
	
	for(int(&ln)[3] : arr){
		for(int &col : ln){
			cout<< col <<endl;
		}
	} 
}
