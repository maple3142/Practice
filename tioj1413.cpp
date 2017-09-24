#include<iostream>
#include<iomanip>
using namespace std;

double f(double x){
	return x*x/(1+x*x);
}
int main(void){
	ios::sync_with_stdio(false);
	double q1=f(1);
	for(int i=2;i<=2008;i++){
		q1+=(f(i)+f(1.0/i));
	}
	cout<<fixed<<setprecision(1)<<q1<<endl;
	cout<<30<<endl;
	return 0;
}


