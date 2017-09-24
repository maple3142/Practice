#include<iostream>
#include<cstring>
using namespace std;

int n,ar[16][16],arr[16][16];
int check(int s){
	memset(arr,0,sizeof(arr));
	for(int i=0;i<n;i++){
		if(s&(1<<i))arr[0][i]=1;
		else if(ar[0][i])return 0x3f3f3f3f;
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<n;j++){
			int sum=0;
			if(i>1)sum+=arr[i-2][j];
			if(j>0)sum+=arr[i-1][j-1];
			if(j<n-1)sum+=arr[i-1][j+1];
			arr[i][j]=sum%2;
			if(ar[i][j]&&(!arr[i][j]))return 0x3f3f3f;
		}
	}
	int c=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(ar[i][j]!=arr[i][j])c++;
		}
	}
	return c;
}
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int aaaa=1;aaaa<=T;aaaa++){
		cin>>n;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>ar[i][j];
		int mn=0x3f3f3f3f;
		for(int i=0;i<1<<n;i++){
			mn=min(mn,check(i));
		}
		if(mn==0x3f3f3f)cout<<"Case "<<aaaa<<": "<<-1<<endl;
		else cout<<"Case "<<aaaa<<": "<<mn<<endl;
	}
	return 0;
}

