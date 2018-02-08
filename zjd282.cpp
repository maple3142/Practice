#include<iostream>
#include<cstring>
using namespace std;

string names[23];
int d[23][23];
int main(void){
	ios::sync_with_stdio(false);
	int n,m,kase=1;
	while(cin>>n>>m){
		if(n==0)break;
		memset(d,0x3f,sizeof(d));
		for(int i=1;i<=n;i++)cin>>names[i];
		int a,b,c;
		while(m--){
			cin>>a>>b>>c;
			d[a][b]=d[b][a]=c;
		}
		for(int i=1;i<=n;i++)d[i][i]=0;
			for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(d[i][k]+d[k][j]<d[i][j]){
						d[i][j]=d[j][i]=d[i][k]+d[k][j];
					}
				}
			}
		}
		int mn=0x3f3f3f3f,ans=0;
		for(int i=1;i<=n;i++){
			int sum=0;
			for(int j=1;j<=n;j++)sum+=d[i][j];
			//cout<<i<<' '<<sum<<endl;
			if(mn>sum){
				mn=sum;
				ans=i;
			}
		}
		cout<<"Case #"<<kase++<<" : "<<names[ans]<<endl;
	}
	return 0;
}

