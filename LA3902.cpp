#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int,int> p;

int n,s,k,cnt=0;
const int user=11111;
const int server=22222;
const int vod=33333;
struct Node{
	int type,dis;
	bool ok;
	vector<int> to;
	Node(){
		ok=false;
		type=server;
		dis=0;
	}
};
Node ar[1001];
vector<p> far;
int par[1001];
void dfs1(int now,int dis,int pa){
	par[now]=pa;
	if(ar[now].type==user&&dis>k)far.push_back(p(dis,now));
	if(ar[now].type==user&&dis<=k)
		ar[now].ok=true;
	for(auto i:ar[now].to){
		if(i!=pa)
			dfs1(i,dis+1,now);
	}
}
void dfs3(int now,int dis,int pa){
	if(dis<=k&&ar[now].type==user){
		ar[now].ok=true;
		return;
	}
	for(auto i:ar[now].to){
		if(i!=pa)
			dfs3(i,dis+1,now);
	}
}
void dfs2(int now,int dis){
	if(dis==k&&ar[now].type==server){
		//cout<<"push "<<now<<endl;
		ar[now].type=vod;
		dfs3(now,0,now);
		cnt++;
		return;
	}
	dfs2(par[now],dis+1);
}
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		cnt=0;
		cin>>n>>s>>k;
		ar[s].type=vod;
		for(int i=0;i<n-1;i++){
			int a,b;
			cin>>a>>b;
			ar[a].to.push_back(b);
			ar[b].to.push_back(a);
		}
		for(int i=1;i<=n;i++){
			if(ar[i].to.size()==1)
				ar[i].type=user;
		}
		dfs1(s,0,s);
		sort(far.begin(),far.end());
		for(int i=far.size()-1;i>=0;i--){
			if(!ar[far[i].second].ok)
				dfs2(far[i].second,0);
		}
		cout<<cnt<<endl;
		far.clear();
		for(int i=1;i<=n;i++){
			ar[i].to.clear();
			ar[i].ok=false;
			ar[i].type=server;
		}
		//memset(ar,0,sizeof(ar[0])*n);
	}
	return 0;
}

