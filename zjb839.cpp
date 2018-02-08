#include<iostream>
#include<cstring>
using namespace std;

string names[51];
int dp[51][51];
int lcs(string a,string b){
	memset(dp,0,sizeof(dp));
	for(int i=0;i<a.length();i++){
		for(int j=0;j<b.length();j++){
			if(a[i]==b[j]){
				dp[i+1][j+1]=dp[i][j]+1;
			}
			else{
				dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
			}
		}
	}
	return dp[a.length()][b.length()];
}
int n;
int par[51];
int find(int a){
	if(a==par[a])return a;
	return par[a]=find(par[a]);
}
void uni(int a,int b){
	par[find(a)]=find(b);
}
int count(int a){
	int r=find(a),cnt=0;
	for(int i=1;i<=n;i++){
		if(find(i)==r)cnt++;
	}
	return cnt;
}
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>names[i];
			par[i]=i;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(find(i)==find(j))continue; 
				if(lcs(names[i],names[j])>=min(names[i].length(),names[j].length())/2.0){
					uni(i,j);
				}
			}
		}
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(count(i),mx);
		}
		cout<<mx<<endl;
	}
	return 0;
}

