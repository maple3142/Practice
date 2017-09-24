#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(void){
	int a,b,c;
	while(cin>>a>>b>>c){
		int x=b*b-4*a*c;
		if(x<0){
			cout<<"No real root"<<endl;
			continue;
		}
		double y=sqrt(x);
		if(x==0)
			cout<<fixed<<setprecision(2)<<"Two same roots x="<<(-1*b+y)/(2*a)<<endl;
		else
			cout<<fixed<<setprecision(2)<<"Two different roots x1="<<(-1*b+y)/(2*a)<<" , x2="<<(-1*b-y)/(2*a)<<endl;
	}
	return 0;
}
