#include<iostream>
#include<queue>
using namespace std;

struct Video{
	int l=0,feel=0;
};
bool max(int a,int b){
	return a>=b?a:b;
}
int main(void){
	int n,l;
	while(cin>>n>>l){
		Video v[n];
		for(int i=0;i<n;i++)
			cin>>v[i].l>>v[i].feel;
		int dp[n][l];
		for(int i=0;i<n;i++){
			for(int tmpl=l;tmpl>0;tmpl-=v[i].l)
				dp[i][l]=max(dp[i-1][l],dp[i-1][l-v[i].l]+v[i].feel);
		}
		priority_queue<int> q;
		for(int i=0;i<n;i++)
			q.push(dp[i][l]);
		cout<<q.top()<<endl;
	}
	return 0;
}

