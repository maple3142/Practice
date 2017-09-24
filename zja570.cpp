#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

struct event{
	int s,e,v;
	event(int s,int e,int v):s(s),e(e),v(v){}
	bool operator<(const event &ev)const{
		if(e==ev.e)
			return s<ev.s;
		return e<ev.e;
	}
};
vector<event> ve;
int dp[1000001];
int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		int s,e,v,mxt=0;
		for(int i=0;i<n;i++){
			cin>>s>>e>>v;
			ve.emplace_back(s,e,v);
			mxt=max(mxt,e);
		}
		sort(ve.begin(),ve.end());
		int idx=0;
		for(int i=1;i<=mxt;i++){
			int mx=-1;
			while(true){
				if(idx==n)break;
				event e=ve[idx];
				if(e.e<=i){
					mx=max(mx,dp[e.s]+e.v);
					idx++;
				}
				else{
					break;
				}
			}
			if(mx==-1){
				mx=dp[i-1];
			}
			dp[i]=mx;
			//cout<<"dp["<<i<<"]="<<dp[i]<<endl;
		}
		cout<<dp[mxt]<<endl;
		memset(dp,0,sizeof(dp));
		ve.clear();
	}
	return 0;
}

