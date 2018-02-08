#include<iostream>
using namespace std;
typedef pair<int,int> pii;

int m,n;
int ar[11][101];
int dp[11][101];
int path[11][101];
int comp(int a,int b){
	if(a<b)return 1;
	if(a>b)return -1;
	return 0;
}
int main(void){
	ios::sync_with_stdio(false);
	while(cin>>m>>n){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				cin>>ar[i][j];
				dp[i][j]=0;
			}
		}
		for(int i=1;i<=m;i++){
			dp[i][n]=ar[i][n];
		}
		for(int i=n-1;i>=1;i--){
			for(int j=1;j<=m;j++){
				int a=(j!=1?j-1:m);
				int b=j;
				int c=(j!=m?j+1:1);
				
				int mn;
				int temp=comp(dp[a][i+1],dp[b][i+1]);
				if(temp==1)mn=a;
				else if(temp==-1)mn=b;
				else mn=min(a,b);
				temp=comp(dp[mn][i+1],dp[c][i+1]);
				if(temp==-1)mn=c;
				else if(temp==0)mn=min(mn,c);
				
				dp[j][i]=dp[mn][i+1]+ar[j][i];
				path[j][i]=mn;
			}
		}
		int mn=0x3f3f3f3f,mni=0;
		for(int i=1;i<=m;i++){
			if(mn>dp[i][1]){
				mn=dp[i][1];
				mni=i;
			}
		}
		int p=mni;
		cout<<p<<' ';
		for(int i=1;i<n;i++){
			cout<<(p=path[p][i]);
			if(i<n-1)cout<<' ';
		}
		cout<<endl;
		cout<<mn<<endl;
	}
	return 0;
}

