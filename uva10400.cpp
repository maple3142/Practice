#include<iostream>
#include<cstring>
using namespace std;

int n,r;
int ar[105];
char opr[105];
bool dp[105][66000];
bool dfs(int now,int sum){
	if(now==n&&sum==r)return true;
	else if(now==n)return false;
	int x=ar[now];
	
	opr[now]='+';
	if(sum+x>32000&&sum+x<-32000){}
	else if(!dp[now][sum+x+32500]&&dfs(now+1,sum+x))return true;
	else dp[now][sum+x+32500]=true;
	
	opr[now]='-';
	if(sum-x>32000&&sum-x<-32000){}
	else if(!dp[now][sum-x+32500]&&dfs(now+1,sum-x))return true;
	else dp[now][sum-x+32500]=true;
	
	opr[now]='*';
	if(sum*x>32000&&sum*x<-32000){}
	else if(!dp[now][sum*x+32500]&&dfs(now+1,sum*x))return true;
	else dp[now][sum*x+32500]=true;
	
	if(x==0)return false;
	if(sum%x!=0)return false;
	
	opr[now]='/';
	if(sum/x>32000&&sum/x<-32000){}
	else if(!dp[now][sum/x+32500]&&dfs(now+1,sum/x))return true;
	else dp[now][sum/x+32500]=true;
	
	return false;
}
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>ar[i];
		cin>>r;
		if(dfs(1,ar[0])){
			for(int i=0;i<n;i++){
				cout<<ar[i];
				if(i+1!=n)cout<<opr[i+1];
			}
			cout<<"="<<r<<endl;
		}
		else{
			cout<<"NO EXPRESSION"<<endl;
		}
		memset(dp,0,sizeof(dp));
	}
	return 0;
}

