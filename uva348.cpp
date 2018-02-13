#include<iostream>
#include<cstring>
#define A first
#define B second
using namespace std;
typedef pair<int,int> pii;

const int MX=11;

pii ar[MX]={};
int dp[MX][MX];
int cut[MX][MX];
void print(int a,int b){
	//cout<<a<<' '<<b<<endl;
	if(a==b){
		cout<<'A'<<a;
		return;
	}
	cout<<'(';
	print(a,cut[a][b]);
	cout<<" x ";
	print(cut[a][b]+1,b);
	cout<<')';
}
int main(void){
	ios::sync_with_stdio(false);
	int n,kase=1;
	while(cin>>n){
		if(n==0)break;
		int a,b;
		for(int i=1;i<=n;i++){
			cin>>a>>b;
			ar[i]=pii(a,b);
		}
		for(int i=1;i<n;i++){
			dp[i][i+1]=ar[i].A*ar[i].B*ar[i+1].B;
			cut[i][i+1]=i;
			//cout<<i<<' '<<i+1<<' '<<cut[i][i+1]<<endl;
		}
		for(int i=2;i<n;i++){
			for(int j=1;j+i<=n;j++){
				int mn=0x3f3f3f3f,mni=0;
				for(int k=j;k<=j+i-1;k++){
					int a=dp[j][k]+dp[k+1][j+i]+ar[j].A*ar[k].B*ar[j+i].B;
					if(mn>a){
						mn=a;
						mni=k;
					}
				}
				dp[j][j+i]=mn;
				cut[j][j+i]=mni;
				//cout<<j<<' '<<j+i<<' '<<cut[j][j+i]<<endl;
			}
		}
		cout<<"Case "<<kase++<<": ";
		print(1,n);
		cout<<endl;
		memset(dp,0,sizeof(dp));
	}
	return 0;
}

