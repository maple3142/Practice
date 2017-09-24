#include<iostream>
using namespace std;

int d[101][101];
int main(void){
	int n;
	while(cin>>n){
		if(n==0)break;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>d[i][j];
				if(d[i][j]==0)d[i][j]=2000000;
			}
		}
		
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(d[i][j] > d[i][k]+d[k][j])d[i][j] = d[i][k]+d[k][j];
				
		int min=2000001;
		for(int i=1;i<=n;i++){
			if(min>d[i][i])min=d[i][i];
		}
		cout<<(min>=2000000?-1:min)<<endl;
	}
	return 0;
}


