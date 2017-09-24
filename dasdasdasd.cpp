#include<iostream>
#include<queue>
using namespace std;

int main(void){
	cin.sync_with_stdio(false);
	int n;
	while(cin>>n){
		if(n==0)break;
		priority_queue<int> q;
		for(int i=0;i<n;i++){
			 int x;
			 cin>>x;
			 q.push(x*-1);
		}
		int cost=0;
		while(q.size()>1){
			int a=q.top()*-1;
			q.pop();
			int b=q.top()*-1;
			q.pop();
			cost+=(a+b);
			q.push((a+b)*-1);
		}
		cout<<cost<<endl;
	}
	return 0;
}


