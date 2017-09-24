#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

queue<string> buf;
int p[1001];
void walk(int a){
	buf.push(to_string(p[a]));
} 
void walk(int a,int b){
	if(a>b)swap(a,b);
	buf.push(to_string(p[a])+" "+to_string(p[b]));
}
void print(){
	while(!buf.empty()){
		cout<<buf.front()<<endl;
		buf.pop(); 
	}
}
int main(void){
	ios::sync_with_stdio(false);
	int T,t;
	cin>>T;
	t=T-1;
	while(T--){
		if(T!=t)cout<<endl;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>p[i];
		sort(p,p+n);
		n--;
		int time=0;
		while(n>=3){
			int a=p[1]+p[0]+p[n]+p[1];
			int b=p[n]+p[0]+p[n-1]+p[0];
			if(a<b){
				time+=a;
				walk(0,1);
				walk(0);
				walk(n,n-1);
				walk(1);
			}
			else{
				time+=b;
				walk(0,n-1);
				walk(0);
				walk(0,n);
				walk(0);
			}
			n-=2;
		}
		if(n==0){
			time+=p[0];
			walk(0);
		}
		else if(n==1){
			time+=p[1];
			walk(0,1);
		} 
		else{
			time+=p[2]+p[0]+p[1];
			walk(0,1);
			walk(0);
			walk(0,2);
		}
		cout<<time<<endl;
		print();
	}
	return 0;
}

