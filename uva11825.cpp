#include<iostream>
#include<cstring>
using namespace std;

int P[17],cover[1<<17],f[1<<17];
int main(void){
	ios::sync_with_stdio(false);
	int n,cse=1;
	while(cin>>n){
		if(n==0)break;
		for(int i=0;i<n;i++){
			int m;
			cin>>m;
			P[i]=1<<i;
			for(int j=0;j<m;j++){
				int x;
				cin>>x;
				P[i]|=(1<<x);
			}
		}
		for(int i=0;i<(1<<n);i++){
			cover[i]=0;
			for(int j=0;j<n;j++){
				if(i&(1<<j))cover[i]|=P[j];
			}	
		}
		int ALL=(1<<n)-1;
		for(int i=1;i<(1<<n);i++){
			for(int j=i;j;j=(j-1)&i){
				if(cover[j]==ALL)f[i]=max(f[i],f[i^j]+1);
			}
		}
		cout<<"Case "<<cse++<<": "<<f[ALL]<<endl;
		memset(f,0,sizeof(f));
	}
	
	return 0;
}

