#include<iostream>
using namespace std;

int ar[55];
int dp[55][55];
int n;
int fn(int i,int j){
	if(i==0&&j==n+1)return 0;
	
	int llen=ar[j]-ar[i-1];
	int rlen=ar[j+1]-ar[i];
	int l=0x3f3f3f3f;
	if(i-1>=0)l=fn(i-1,j)+llen;
	int r=0x3f3f3f3f;
	if(j+1<=n+1)r=fn(i,j+1)+rlen;
	return min(l,r);
}
int main(void){
	ios::sync_with_stdio(false);
	int l;
	while(cin>>l){
		if(l==0)break;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>ar[i];
		}
		ar[n+1]=l;
		for(int i=0;i<=n;i++){
			cout<<i<<' '<<fn(i,i+1)<<endl;
		}
		cout<<"The minimum cutting is "<<fn(1,2)<<'.'<<endl;
	}
	return 0;
}

