#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

struct lesson{
	vector<int> to;
	lesson(){
		
	}
};
lesson ls[1001];
int want[1001];
int main(void){
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m){
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			ls[a].to.push_back(b);
			want[b]++;
		}
		queue<int> q;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			q.push(x);
		}
		bool yes=true;
		while(!q.empty()){
			int i=q.front();
			if(want[i]==0){
				vector<int> v=ls[i].to;
				for(int i=0;i<v.size();i++){
					if(want[v[i]]>0)want[v[i]]--;	
				}
			}
			else{
				yes=false;
			}
			ls[i].to.clear();
			q.pop();
		}
		cout<<(yes?"YES":"NO")<<endl;
		memset(want,0,sizeof(want));
	}
	return 0;
}


