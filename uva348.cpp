#include<iostream>
#include<cstring>
#define A first
#define B second
using namespace std;
typedef pair<int,int> pii;
typedef long long int ll;

const int MX=11;

pii ar[MX]={};
ll dp[MX][MX];
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
				ll a=dp[j][j+i-1]+ar[j].A*ar[j+i].A*ar[j+i].B;
				ll b=dp[j+1][j+i]+ar[j].A*ar[j].B*ar[j+i].B;
				if(a>b){
					dp[j][j+i]=b;
					cut[j][j+i]=cut[j][j+i-1];
				}
				else{
					dp[j][j+i]=a;
					cut[j][j+i]=cut[j+1][j+i];
				}
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

