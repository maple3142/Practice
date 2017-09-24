#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

struct point{
	int h;
	int step;
	vector<int> to;
	point(){
		
	}
};
point pts[10001];
bool vis[10001];
int endh;
bool slide_stuck,walk_stuck;
int slide(int start){
	queue<int> q;
	pts[start].step=0;
	q.push(start);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		if(pts[t].h==endh){
			return pts[t].step;
		}
		vector<int> v=pts[t].to;
		int mxi=-1,mxh=0;
		for(int i=0;i<v.size();i++){
			if(pts[v[i]].h<=pts[t].h){
				if(mxh<=pts[t].h-pts[v[i]].h){
					mxh=pts[t].h-pts[v[i]].h;
					mxi=v[i];
				}
			}
		}
		if(mxi==-1)continue;
		if(vis[mxi])continue;
		q.push(mxi);
		pts[mxi].step=pts[t].step+1;
		vis[mxi]=true;
	}
	slide_stuck=true;
	return 0;
}
int walk(int start){
	queue<int> q;
	pts[start].step=0;
	q.push(start);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		if(pts[t].h==endh){
			return pts[t].step;
		}
		vector<int> v=pts[t].to;
		bool yes=false;
		for(int i=0;i<v.size();i++){
			if(!vis[v[i]]){
				pts[v[i]].step=pts[t].step+6;
				q.push(v[i]);
				vis[v[i]]=true;
			}
		}
	}
	walk_stuck=true;
	return 0;
}
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	int cse=1;
	while(T--){
		int n,m,s;
		cin>>n>>m>>s;
		endh=0x3f3f3f3f;
		for(int i=0;i<n;i++){
			int k;
			cin>>k;
			pts[i].h=k;
			endh=min(endh,pts[i].h);
		}
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			pts[a].to.push_back(b);
			pts[b].to.push_back(a);
		}
		int sl=slide(s);
		memset(vis,0,sizeof(vis)); 
		int wl=walk(s);
		//cout<<sl<<" "<<wl<<endl;
		cout<<"Case #"<<cse++<<": ";
		if(slide_stuck&&walk_stuck){
			cout<<"Call 119!"<<endl;
		}
		else if(slide_stuck){
			cout<<wl<<endl;
		}
		else{
			cout<<abs(wl-sl)<<endl; 
		}
		slide_stuck=walk_stuck=false;
		for(int i=0;i<n;i++){
			pts[i].to.clear();
		}
		memset(vis,0,sizeof(vis)); 
	}
	return 0;
}

