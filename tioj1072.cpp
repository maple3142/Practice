#include<iostream>
#include<algorithm>
using namespace std;

struct food{
	int time;
	int etime;
	food(){
	}
	food(int a,int b){
		time=a;
		etime=b;
	}
};
food f[10005];
bool comp(food a,food b){
	return a.etime>b.etime;
}
int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		if(n==0)break;
		for(int i=0;i<n;i++){
			int a,b;
			cin>>a>>b;
			f[i]=food(a,b);
		}
		sort(f,f+n,comp);
		int time=0,eating=0;
		for(int i=0;i<n;i++){
			if(eating>0)eating-=f[i].time;
			eating=max(eating,f[i].etime);
			time+=f[i].time;
		}
		cout<<time+eating<<endl;
	}
	return 0;
}


