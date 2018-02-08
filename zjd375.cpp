#include<iostream>
#include<algorithm>
using namespace std;

int n,m,sum;
int ar[21];
bool used[21];
bool dfs(int edge,int cur,int st){
	if(edge==3)return true;
	if(cur==sum/4)
		if(dfs(edge+1,0,1))return true;
	for(int i=st;i<m;i++){
		if(used[i] || cur+ar[i]>sum/4)continue;
		used[i]=true;
		bool ok=dfs(edge,cur+ar[i],i);
		used[i]=false;
		if(ok)return true;
	}
	return false;
}
int main(void){
	ios::sync_with_stdio(false);
	cin>>n;
	while(n--){
		cin>>m;
		int mx=0;
		sum=0;
		for(int i=1;i<=m;i++){
			cin>>ar[i];
			sum+=ar[i];
			mx=max(mx,ar[i]);
		}
		sort(ar+1,ar+1+m,greater<int>());
		if(sum%4!=0)cout<<"no"<<endl;
		else if(mx>sum/4)cout<<"no"<<endl;
		else {
			if(dfs(0,0,1))cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		}
		
	}
	return 0;
}

