#include<iostream>
#include<cstring>
using namespace std;

int ar[2005],arr[4005];
int main(void){
	ios::sync_with_stdio(false);
	string s;
	while(cin>>s){
		int len=s.length();
		for(int i=0;i<len;i++)
			ar[i]=s[len-i-1]-'0';
		for(int i=0;i<len;i++){
			for(int j=0;j<len;j++){
				arr[i+j]+=ar[i]*ar[j];
			}
		}
		for(int i=0;i<len*2;i++){
			if(arr[i]>=10){
				arr[i+1]+=arr[i]/10;
				arr[i]%=10;
			}
		}
		int t=len-1;
		while(arr[t]==0)t--;
		if(t<0||(t==0 && arr[t]==1)){
			cout<<"Not an Automorphic number."<<endl;
		}
		else{
			bool is=true;
			for(int i=0;i<len;i++){
				if(ar[i]!=arr[i]){
					is=false;
					break;
				}
			}
			if(is)cout<<"Automorphic number of "<<len<<"-digit."<<endl;
			else cout<<"Not an Automorphic number."<<endl;
		}
		memset(ar,0,sizeof(ar));
		memset(arr,0,sizeof(arr));
	}
	return 0;
}

