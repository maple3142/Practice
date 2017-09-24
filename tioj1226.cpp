#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef long long int ll;

struct event{
	ll time;
	int f;
};
struct point{
	int in=0,step=0;
	vector<event> from;
	vector<int> to;
	ll time=0;
}p[1005];
string name[105];
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T,game=1;
	cin>>T;
	while(T--){
		int n,v,e;
		cin>>n>>v>>e;
		for(int i=1;i<=n;i++){
			cin>>name[i];
		}
		for(int i=1;i<=e;i++){
			int x,y,z;
			cin>>x>>y>>z;
			event ev=(event){z,x};
			p[x].to.push_back(y);
			p[y].from.push_back(ev);
			p[y].in++;
		}
		queue<int> q;
		q.push(0);
		p[0].step=1;
		while(!q.empty()){
			int px=q.front();
			q.pop();
			for(int j=0;j<p[px].to.size();j++){
				int i=p[px].to[j];
				p[i].in--;
				if(p[i].in==0){
					q.push(i);
					int x=i;
					for(int j=0;j<p[x].from.size();j++){
						event i=p[x].from[j];
						p[x].step+=p[i.f].step;
						p[x].time+=(i.time)%32768*p[i.f].step%32768;
						p[x].time%=32768;
						p[x].time+=p[i.f].time%32768;
						p[x].time%=32768;
					}
				}
			}
		}
		cout<<"Game #"<<game++<<endl;
		for(int i=1;i<=n;i++){
			cout<<name[i]<<": "<<p[i].time%32768<<endl;
		}
		for(int i=0;i<=v;i++){
			p[i].to.clear();
			p[i].from.clear();
			p[i].in=0;
			p[i].time=0;
			p[i].step=0;
		}
	}
	return 0;
}
