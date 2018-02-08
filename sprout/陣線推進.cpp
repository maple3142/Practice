#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

vector<int> to[1005];
int in[1005];
int out[1005];
bool vis[1005];
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			to[a].push_back(b);
			out[a]++;
			in[b]++;
		}
		
		vector<int> typo;
		queue<int> q;
		for(int i=0;i<n;i++){
			if(in[i]==0){
				q.push(i);
			}
		}
		bool ok;
		while(!q.empty()){
			int t=q.front();
			q.pop();
			vis[t]=true;
			out[t]=0;
			sort(to[t].begin(),to[t].end());
			for(int i=0;i<to[t].size();i++){
				in[to[t][i]]--;
				if(in[to[t][i]]==0)q.push(to[t][i]);
			}
			typo.push_back(t);
		}
		ok=true;
		for(int i=0;i<n;i++)
			ok=min(ok,vis[i]);
		if(ok){
			for(int x:typo){
				cout<<x<<" ";
			}
			cout<<endl;
		}
		else{
			cout<<"QAQ"<<endl;
		}
		end:
		memset(to,0,sizeof(to));
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		memset(vis,0,sizeof(vis));
	}
	return 0;
}

