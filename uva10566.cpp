#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double x,y,c;
double calc(double l){
	double ld=sqrt(y*y-l*l);
	double rd=sqrt(x*x-l*l);
	return c/ld+c/rd;
}
double search(double l,double r){
	double mid=(l+r)/2;
	double rr=calc(mid);
	if(abs(1-rr)<0.00000001)
		return mid;
	else if(rr<1)
		return search(mid,r);
	else
		return search(l,mid);
}
int main(void){
	ios::sync_with_stdio(false);
	while(cin>>x>>y>>c){
		cout<<fixed<<setprecision(3)<<search(0,min(x,y))<<endl;
	}
	return 0;
}

