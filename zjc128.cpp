#include<iostream>
#include<unordered_map>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;

unordered_map<string,int> mp;
string ump[201];
int ccnt=0;
int toid(string ct){
	if(!mp.count(ct)){
		mp[ct]=ccnt;
		ump[ccnt]=ct;
		ccnt++;
	}
	return mp[ct];
}
vector<pii> to[201];
bool inq[201];
int d[201];
int main(void){
	ios::sync_with_stdio(false);
	int n,r,kase=1;
	while(cin>>n>>r){
		if(n==r&&r==0)break;
		cout<<"Scenario #"<<kase++<<endl;
		string a,b;
		int x;
		for(int i=0;i<r;i++){
			cin>>a>>b>>x;
			int aa=toid(a);
			int bb=toid(b);
			to[aa].push_back(pii(bb,x));
			to[bb].push_back(pii(aa,x));
		}
		cin>>a>>b;
		int s=toid(a);
		int e=toid(b);
		
		d[s]=0x3f3f3f3f;
		queue<int> q;
		q.push(s);
		while(!q.empty()){
			int now=q.front();
			q.pop();
			inq[now]=false; 
			
			for(pii p:to[now]){
				if(d[p.first]<min(d[now],p.second)){
					d[p.first]=min(d[now],p.second);
					if(!inq[p.first]){
						q.push(p.first);
						inq[p.first]=true;
					}
				}
			}
		}
		cout<<d[e]<<" tons"<<endl;
		
		memset(d,0,sizeof(d));
		ccnt=0;
		memset(to,0,sizeof(to));
	}
	return 0;
}

