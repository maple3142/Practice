#include<iostream>
#include<vector>
using namespace std;

const int MX=255;
int in[MX];
vector<int> to[MX];
long long int dp[MX];
int main(void){
	ios::sync_with_stdio(false);
	int v,e,m;
	while(cin>>v>>e>>m){
		int a,b;
		while(e--){
			cin>>a>>b;
			to[a].push_back(b);
			in[b]++;
		}
		int s,t;
		cin>>s>>t;
		
		vector<int> vec;
		for(int i=0;i<v;i++){
			int p=-1;
			for(int j=0;j<v;j++){
				if(in[j]==0)p=j;
			}
			vec.push_back(p);
			for(int x:to[p]){
				in[x]--;
			}
		}
		
		dp[s]=1;
		for(int i=0;i<vec.size();i++){
			int p=vec[i];
			for(int x:to[p]){
				dp[x]+=dp[p];
				dp[x]%=m;
			}
		}
		cout<<dp[t]<<endl;
	}
	return 0;
}

