#include<iostream>
#include<cstring>
using namespace std;
typedef long long int ll;
ll ar[205];
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		for(int i=0;i<s.length();i++){
			if(s[i]=='0'){
				ar[i+1]=max(ar[i+1],ar[i]);
			}
			else{
				ll x=0;
				for(int j=i;j<s.length();j++){
					x=x*10+s[j]-'0';
					if(x>2147483647LL)break;
					ar[j+1]=max(ar[j+1],ar[i]+x);
				}
			}
		}
		cout<<ar[s.length()]<<endl;
		memset(ar,0,sizeof(ar));
	}
	return 0;
}

