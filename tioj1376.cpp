#include<iostream>
#include<vector>
using namespace std;

vector<int> plist[100];
int old[10];
int nw[10];
bool ovis[10];
bool nvis[10];
int n,m,mx=0;
void DFS(bool m,int id,int l){
	if(m){
		ovis[id]=true;
		for(auto i:plist[id]){
			if(!nvis[i])
				DFS(false,i,l+1);
		}
		ovis[id]=false;
	}
	else{
		nvis[id]=true;
		for(int i=0;i<n;i++){
			if(!ovis[i])
				DFS(true,i,l+1);
		}
		nvis[id]=false;
	}
	if(l>mx)mx=l;
}
int main(void){
	cin.sync_with_stdio(false);
	while(cin>>n>>m){
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			plist[a].push_back(b);
		}
		for(int i=0;i<n;i++){
			if(!ovis[i])
				DFS(true,i,1);
		}
		cout<<mx/2<<endl;
		
		mx=0;
	}
	return 0;
}

