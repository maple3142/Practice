#include<iostream>
#include<cstring>
#define debug 1
using namespace std;

int ar[1001];
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>ar[i];
		}
		int offset=1;
		int mn=0x3f3f3f3f,mni=-1,sum=0;
		while(offset<n){
			for(int i=offset;i<=n-1;i++){
				if(ar[i]+ar[i+1]<mn){
					mn=ar[i]+ar[i+1];
					mni=i;
				}
			}
			#if debug==1
			cout<<"merge "<<ar[mni]<<" "<<ar[mni+1]<<" "<<endl;
			#endif
			sum+=(ar[mni+1]+=ar[mni]);
			for(int i=mni;i>=offset;i--){
				ar[i]=ar[i-1];
			}
			#if debug==1
			for(int i=offset+1;i<=n;i++){
				cout<<ar[i]<<" ";
			}
			cout<<endl;
			#endif
			offset++;
			mn=0x3f3f3f3f;
			mni=-1;
		}
		cout<<sum<<endl;
	}
	return 0;
}
