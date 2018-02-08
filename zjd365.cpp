#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,char> pic;

const int MX=100;
int ar[MX][MX];
bool vis[MX][MX];
int X[]={1,0,-1,0};
int Y[]={0,1,0,-1};
int h,w;
bool dfs(int x,int y,int c){
	vis[x][y]=true;
	for(int i=0;i<4;i++){
		int xx=x+X[i];
		int yy=y+Y[i];
		if(vis[xx][yy])continue;
		if(ar[xx][yy]!=c)continue;
		if(xx<1||yy<1||xx>h||yy>w)continue;
		dfs(xx,yy,c);
	}
}
int cnt[26];
int main(void){
	ios::sync_with_stdio(false);
	int n,world=1;
	cin>>n;
	while(n--){
		cout<<"World #"<<world++<<endl;
		cin>>h>>w;
		char tmp;
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				cin>>tmp;
				ar[i][j]=tmp-'a';
			}
		}
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				if(!vis[i][j]){
					dfs(i,j,ar[i][j]);
					cnt[ar[i][j]]++;
				}
			}
		}
		vector<pic> v;
		for(int i=0;i<26;i++){
			if(!cnt[i])continue;
			v.emplace_back(cnt[i],'a'+i);
		}
		sort(v.begin(),v.end(),[](const pic &a,const pic &b){
			if(a.first==b.first){
				return a.second<b.second;
			}
			return a.first>b.first;
		});
		for(pic x:v){
			cout<<x.second<<": "<<x.first<<endl;
		}
		memset(vis,0,sizeof(vis));
		memset(cnt,0,sizeof(cnt));
	}
	return 0;
}

