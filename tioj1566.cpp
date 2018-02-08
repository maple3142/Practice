#include<iostream>
#include<queue>
#include<utility>
using namespace std;
typedef long long int ll;
typedef pair<ll,int> pii;

int main(void){
	ios::sync_with_stdio(false);
	ll n,m,k;
	while(cin>>n>>m>>k){
		int x;
		queue<pii> r;
		priority_queue<pii> q,qq;
		for(int i=1;i<=n+m;i++){
			if(i<=n){
				cin>>x;
				q.push(pii(x,i));
				qq.push(pii(-x,i));
			}
			ll rg=i-m+1;
			if(rg<=0)rg=1;
			while(!q.empty()&&q.top().second<rg){
				q.pop();
			}
			while(!qq.empty()&&qq.top().second<rg){
				qq.pop();
			}
			if(!q.empty()&&!qq.empty()&&q.top().first+qq.top().first==k){
				r.push(pii(rg,(i>n?n:i)));
			}
		}
		cout<<r.size()<<endl;
		while(!r.empty()){
			pii x=r.front();
			cout<<x.first<<" "<<x.second<<endl;
			r.pop();
		}
		
	}
	return 0;
}

