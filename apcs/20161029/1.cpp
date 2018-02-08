#include<iostream>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int a,b,c;
	while(cin>>a>>b>>c){
		if(a>b)swap(a,b);
		if(a>c)swap(a,c);
		if(b>c)swap(b,c);
		cout<<a<<" "<<b<<" "<<c<<endl;
		if(a+b<=c)cout<<"No"<<endl;
		else if(a*a+b*b<c*c)cout<<"Obtuse"<<endl;
		else if(a*a+b*b==c*c)cout<<"Right"<<endl;
		else cout<<"Acute"<<endl; 
	}
	return 0;
}

