#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node{
	int delay,prev,in,out;
	vector<int> from,to;
	node(){
		
	}
}ar[100005];
bool vis[100005];
int find(int x){
	if(vis[x])return 0;
	vis[x]=true;
	if(x==0)return 0;
	else return find(ar[x].prev)+1;
}
int main(void){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>ar[i].delay;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		ar[a].to.push_back(b);
		ar[a].out++;
		ar[b].from.push_back(a);
		ar[b].in++;
	}
	vector<int> typo;
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(ar[i].from.size()==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int t=q.front();
		q.pop();
		ar[t].out=0;
		for(int i=0;i<ar[t].to.size();i++){
			ar[ar[t].to[i]].in--;
			if(ar[ar[t].to[i]].in==0)q.push(ar[t].to[i]);
		}
		typo.push_back(t);
	}
	int mxe=0,mxeid=0;
	for(int i=0;i<typo.size();i++){
		int now=typo[i];
		auto f=ar[now].from;
		int mxd=0,mxdid=0;
		for(int i=0;i<f.size();i++){
			if(mxd<ar[f[i]].delay){
				mxd=ar[f[i]].delay;
				mxdid=f[i];
			}
		}
		ar[now].delay+=mxd;
		ar[now].prev=mxdid;
		
		if(ar[now].to.size()==0){
			if(mxe<=ar[now].delay){
				mxe=ar[now].delay;
				mxeid=now;
			}
		}
	}
	vector<int> ve;
	for(int i=0;i<typo.size();i++){
		int now=typo[i];
		if(ar[now].to.size()==0){
			if(mxe==ar[now].delay){
				ve.push_back(now);
			}
		}
	}
	int sum=0;
	for(int x:ve){
		sum+=find(x);
	}
	cout<<sum<<endl;
	return 0;
}

