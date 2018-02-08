#include<iostream>
using namespace std;
typedef pair<int,int> pii;

pii ar[201812];
bool vis[201812];
int dice[201812];
int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int t,v;
	for(int i=2;i<n;i++){
		cin>>t;
		if(t==0){
			ar[i]=pii(1,0);
			continue;
		}
		cin>>v;
		ar[i]=pii(t,v);
	}
	int m;
	cin>>m;
	int now=1,cnt=0;
	for(int i=1;i<=m;i++){
		cin>>dice[i];
	}
	for(int i=1;i<=m;i++){
		now+=dice[i];
		cnt++;
		//cout<<"dice to: "<<now<<endl;
		if(now==n)break;
		vis[now]=true;
		
		pii act=ar[now];
		if(act.first==1)now+=act.second;
		if(act.first==2)now-=act.second;
		if(act.first==3)now=act.second;
		
		if(now<1)now=1;
		if(now>n)now=n;
		
		//cout<<"block to: "<<now<<endl;
		if(now==n)break;
	}
	if(now==n)cout<<1<<' '<<cnt<<endl;
	else cout<<-1<<' '<<now<<endl; 
	return 0;
}

