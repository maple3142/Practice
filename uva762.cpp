#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;

unordered_map<string,int> mp;
string ump[10000];
int ccnt=0;
int toid(string ct){
	if(!mp.count(ct)){
		mp[ct]=ccnt;
		ump[ccnt]=ct;
		ccnt++;
	}
	return mp[ct];
}
vector<int> to[10000];
bool vis[10000];
struct X{
	int now;
	X* prev;
	X(int n){
		now=n;
		prev=nullptr;
	}
	X(int n,X *f){
		now=n;
		prev=f;
	}
};
int main(void){
	ios::sync_with_stdio(false);
	int m;
	int kase=1;
	while(cin>>m){
		if(kase>1)cout<<endl;
		string a,b;
		while(m--){
			cin>>a>>b;
			int aa=toid(a),bb=toid(b);
			to[aa].push_back(bb);
			to[bb].push_back(aa);
		}
		cin>>a>>b;
		int st=toid(a),ed=toid(b);
		
		queue<X> q;
		q.emplace(st);
		X *end=nullptr;
		while(!q.empty()){
			X *now=&q.front();
			q.pop();
			
			if(now->now==ed){
				end=now;
				break;
			}
			
			for(int c:to[now->now]){
				if(vis[c])continue;
				
				q.emplace(c,now);
				vis[c]=true;
			}
		}
		
		stack<pii> stk;
		if(end!=nullptr){
			while(end->prev!=nullptr){
				stk.push(pii(end->prev->now,end->now));
				end=end->prev;
			}
			while(!stk.empty()){
				pii p=stk.top();
				stk.pop();
				cout<<ump[p.first]<<' '<<ump[p.second]<<endl;
			}
		}
		else{
			cout<<"No route"<<endl;
		}
		
		//memset(ump,0,sizeof(ump));
		memset(to,0,sizeof(to));
		memset(vis,0,sizeof(vis));
		mp.clear();
		kase++;
		ccnt=0;
	}
	return 0;
}

