#include<iostream>
using namespace std;

int main(void){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b,c,d,e,f;
		cin>>a>>b>>c>>d>>e>>f;
		int y=(c*d-f*a)/(b*d-e*a);
		int x;
		if(d==0)
			x=(c-b*y)/a;
		else
			x=(f-e*y)/d;
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}


