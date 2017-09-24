#include<iostream>
using namespace std;

int main(void){
	int n;
	cin>>n;
	for(int u=0;u<n;u++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(b/a==d/c){
			cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<d*d/c<<endl;
		}
		else{
			cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<d+d-c<<endl;
		}
	}
	return 0;
}


