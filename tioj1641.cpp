#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<iomanip>
using namespace std;
typedef pair<int,double> pii;

vector<pii> to[10005];
double d[10005];
bool inq[10005];
int n,m,s,t;
int main(void){
	ios::sync_with_stdio(false);
	cin>>n>>m>>s>>t;
	int a,b;
	double c;
	while(m--){
		cin>>a>>b>>c;
		to[a].push_back(pii(b,log10(c+1)));
	}
	for(int i=1;i<=n;i++)d[i]=0x3f3f3f3f;
	
	queue<int> q;
	q.push(s);
	d[s]=0;
	inq[s]=true;
	while(!q.empty()){ //spfa
		int now=q.front();
		q.pop();
		inq[now]=false;
		
		for(pii p:to[now]){
			if(d[p.first]<=d[now]+p.second)continue;
			d[p.first]=d[now]+p.second;
			
			if(inq[p.first])continue;
			inq[p.first]=true;
			q.push(p.first);
		}
	}
	double ans=pow(10,d[t]-floor(d[t]));
	cout<<fixed<<setprecision(2)<<ans<<"e+";
	cout<<setw(3)<<setfill('0')<<(int)floor(d[t])<<endl;
	return 0;
}

