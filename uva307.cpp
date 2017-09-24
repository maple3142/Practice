#include<iostream>
#include<cstring>
using namespace std;

int ar[100];
bool vis[100];
int N;
bool ty(int n,int nl,int l){
	
}
int main(void){
	ios::sync_with_stdio(false);
	while(cin>>N){
		if(N==0)break;
		int sum=0;
		for(int i=0;i<N;i++){
			cin>>ar[i];
			sum+=ar[i];
		}
		for(int i=1;i<=sum;i++){
			if(sum%i==0){
				int c=0,q=sum/i;
				for(int j=0;j<q;j++)
					if(ty(0,0,i))
						c++;
				if(c==q)cout<<i<<endl;
				memset(vis,0,sizeof(vis));
			}
		}
	}
	return 0;
}

