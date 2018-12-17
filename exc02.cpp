#include<iostream>
#include<string>

using namespace std;

//int main(){
//	string name;
//	int score;
//	cout<<"이름 입력 : ";
//	cin>>name;
//	cout<<"점수 입력 : ";
//	cin>>score;
//	cout<<name<<"님의 점수는 "<<score<<"점입니다."<<endl; 
//}
int main(){
	int arr[2][3] = {{1,2,3},{4,5,6}};
	
	for(int(&ln)[3] : arr){
		for(int &col : ln){
			cout<< col <<endl;
		}
	} 
}
