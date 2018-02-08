#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

struct llog{
	int a,b,c;
	llog fmt(){
		//cout << a << b << c << "\n";
		if(a>b&&b>c)return *this;
		else if(a<b&&b<c)return *this;
		else return ((llog){c,a,b}).fmt();
	}
	void print(){
		cout<<a<<' '<<b<<' '<<c<<endl;
	}
	bool operator<(const llog& x)const{
		if(a==x.a){
			if(b==x.b){
				return c<x.c;
			}
			return b<x.b;
		}
		return a<x.a;
	}
};

int n;
vector<llog> v;
bool ok[101][101];
int vis[101];
bool vis2[101][101][101];
void dfs(int now,int deep=0,int prv=-1,int pprv=-1){
	if(deep==3&&vis[now]==1&&!vis2[pprv][prv][now]&&now!=prv&&now!=pprv&&prv!=pprv){
		v.push_back((llog){pprv,prv,now});
		vis2[pprv][prv][now]=vis2[now][pprv][prv]=vis2[prv][now][pprv]=true;
		return;
	}
	if(deep==3)return;
	vis[now]++;
	for(int i=1;i<=n;i++){
		if(!ok[now][i])continue;
		if(prv==-1)dfs(i,deep+1,now);
		else if(pprv==-1)dfs(i,deep+1,now,prv);
		else dfs(i,deep+1,now,prv);
	}
	vis[now]--;
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>ok[i][j];
			}
		}
		for(int i=1;i<=n;i++)dfs(i);
		for(int i=0;i<v.size();i++)v[i]=v[i].fmt();
		sort(v.begin(),v.end());
		for(llog l:v)l.print();
		cout<<"total:"<<v.size()<<endl<<endl;
		
		v.clear();
		memset(vis2,0,sizeof(vis2));
	}
	return 0;
}

