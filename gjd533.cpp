#include<iostream>
using namespace std;

int main(void){
	int n;
	cin>>n;
	for(int u=0;u<n;u++){
		double a,b,c,d;
		cin>>a>>b>>c>>d;
		if(b!=0 || d!=0)
			cout<<"No"<<endl;
		else{
			if(a>c)
				cout<<">"<<endl;
			else if(a<c)
				cout<<"<"<<endl;
			else
				cout<<"="<<endl;
		}
	}
	return 0;
}


