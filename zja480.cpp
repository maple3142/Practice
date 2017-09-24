#include<iostream>
using namespace std;

struct psys{
	int x,y,fdis2;
	psys(int a,int b){
		x=a;
		y=b;
		fdis2=0;
	}
};
int max(int a,int b){
	return (a>b?a:b);
}
int main(void){
	ios::sync_with_stdio(false);
	//initPSYS
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	psys p1=psys(a,b),p2=psys(c,d);
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		double d1_2=(x-p1.x)*(x-p1.x)+(y-p1.y)*(y-p1.y);
		double d2_2=(x-p2.x)*(x-p2.x)+(y-p2.y)*(y-p2.y);
		if(d1_2>d2_2){
			p2.fdis2=max(p2.fdis2,d2_2);
		}
		else{
			p1.fdis2=max(p1.fdis2,d1_2);
		}
	}
	cout<<p1.fdis2+p2.fdis2<<endl;
	return 0;
}


