#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(void){
	cin.sync_with_stdio(false);
	double r,n;
	while(cin>>r>>n){
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
		}
		int s=round(n/r);
		int m=0;
		while(s>=60){
			m++;
			s-=60;
		}
		cout<<m<<":"<<setfill('0')<<setw(2)<<s<<endl;
	}
	return 0;
}


