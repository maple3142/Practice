#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

vector<int> to[100005];
int in[100005];
int out[100005];
bool vis[100005];
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
		priority_queue<int> pq;
		for(int i=0;i<n;i++){
			if(in[i]==0){
				q.push(i);
			}
		}
		bool ok;
		while(true){
			while(!q.empty()){
				int t=q.front();
				q.pop();
				vis[t]=true;
				out[t]=0;
				for(int i=0;i<to[t].size();i++){
					in[to[t][i]]--;
					if(in[to[t][i]]==0)pq.push(-to[t][i]);
				}
				typo.push_back(t);
			}
			if(pq.empty())break;
			q.push(-pq.top());
			pq.pop();
		}
		ok=true;
		for(int i=0;i<n;i++)
			ok=min(ok,vis[i]);
		if(ok){
			for(int i=0;i<typo.size()-1;i++){
				cout<<typo[i]<<" ";
			}
			cout<<typo[typo.size()-1];
		}
		else{
			cout<<"QAQ";
		}
		cout<<endl;
		for(int i=0;i<n;i++){
			to[i].clear();
		}
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		memset(vis,0,sizeof(vis));
	}
	return 0;
}

