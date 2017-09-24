#include<iostream>
using namespace std;

int f(int n){
	if(n==0)return 1;
	cout<<n<<(n<=1?" ":" * ");
	return f(n-1)*n;
}
int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		if(n!=0){
			cout<<n<<"! = ";
			cout<<"= "<<f(n)<<endl;
		}
		else{
			cout<<"0! = 1 = 1"<<endl;
		}
		
	}
	return 0;
}

