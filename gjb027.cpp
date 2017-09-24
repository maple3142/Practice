#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

int min3(int a,int b,int c){
	priority_queue<int> q;
	q.push(-1*a);
	q.push(-1*b);
	q.push(-1*c);
	return (-1*q.top());
}

int main(void){
	int h,w;
	while(cin>>h>>w){
		int arr[h+1][w+1];
		int dp[h+1][w+1];
		priority_queue<int> q;
		
		memset(arr,1,sizeof(arr));
		memset(dp,0,sizeof(dp));
		
		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++){
				cin>>arr[i][j];
			}
		
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				if(arr[i][j]!=1)
					dp[i][j]=min3(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
				else
					dp[i][j]=0;
				q.push(dp[i][j]);
			}
		}
		
		cout<<q.top()*q.top()<<endl;
		while(!q.empty())
			q.pop();
		
	}
	return 0;
}
