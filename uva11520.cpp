#include<iostream>
#include<cstring>
using namespace std;

char ar[12][12];
int X[]={1,0,-1,0};
int Y[]={0,1,0,-1};
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int cse=1;cse<=T;cse++){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>ar[i][j];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(ar[i][j]=='.'){
					for(char c='A';c<='Z';c++){
						bool ok=true;
						for(int k=0;k<4;k++){
							if(ar[i+X[k]][j+Y[k]]==c){
								ok=false;
								break;
							}
						}
						if(ok){
							ar[i][j]=c;
							break;
						}
					}
				}
			}
		}
		cout<<"Case "<<cse<<":"<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<ar[i][j];
			}
			cout<<endl;
		}
		memset(ar,0,sizeof(ar));
	}
	return 0;
}

