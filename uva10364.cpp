#include<iostream>
#include<algorithm>
using namespace std;

int stick[25],len,m;
bool dfs(int now,int sum,int next,bool vis[]){
	if(now==3)return true;
	if(sum==len){
		if(dfs(now+1,0,0,vis)){//next edge
			return true;
		}
	}
	for(int i=next;i<m;i++){
		if(!vis[i] && sum+stick[i]<=len){
			vis[i]=true;
			if(dfs(now,sum+stick[i],i,vis))
				return true;
			vis[i]=false;
		}
	}
	return false;
}
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		cin>>m;
		int sum=0,mx=0;
		for(int i=0;i<m;i++){
			cin>>stick[i];
			sum+=stick[i];
			mx=max(mx,stick[i]);
		}
		len=sum/4;
		if(sum%4!=0 || mx>len){
			cout<<"no"<<endl;
			continue;
		}
		sort(stick,stick+m,[](const int &a,const int &b){
			return a>b;
		});
		bool vis[25]={};
		if(dfs(0,0,0,vis))cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}

