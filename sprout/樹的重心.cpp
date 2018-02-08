#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

struct node{
	vector<int> to;
	int par;
	//h=heigh,c=child
	int h1,c1;//first
	int h2,c2;//second
	node(){
		c1=c2=h1=h2=0;
		par=-1;
		to.clear();
	}
};
node tree[100005];
void re(int x,int h,int c){
	if(h>tree[x].h1){
		tree[x].h2=tree[x].h1;
		tree[x].c2=tree[x].c1;
		tree[x].h1=h;
		tree[x].c1=c;
	}
	else if(h>tree[x].h2){
		tree[x].h2=h;
		tree[x].c2=c;
	}
}
void dfs(int x){
	tree[x].h1=tree[x].h2=0;
	for(int i=0;i<tree[x].to.size();i++){
		int c=tree[x].to[i];
		if(tree[x].par!=c){
			tree[c].par=x;
			dfs(c);
			re(x,tree[c].h1+1,c);
		}
	}
}
void ddfs(int x){
	if(tree[x].par!=x){
		int p=tree[x].par;
		if(tree[p].c1==x)
			re(x,tree[p].h2+1,p);
		else
			re(x,tree[p].h1+1,p);
	}
	for(int i=0;i<tree[x].to.size();i++){
		int c=tree[x].to[i];
		if(tree[x].par!=c){
			ddfs(c);
		}
	}
}
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n-1;i++){
			int a,b;
			cin>>a>>b;
			tree[a].to.push_back(b);
			tree[b].to.push_back(a);
		}
		tree[0].par=0;
		dfs(0);
		ddfs(0);
		int mnh=0x3f3f3f3f;
		for(int i=0;i<n;i++){
			mnh=min(mnh,tree[i].h1);
		}
		bool print=true;
		for(int i=0;i<n;i++){
			if(mnh==tree[i].h1&&print){
				cout<<i<<endl;
				print=false;
			}
			tree[i]=node();
		}
	}
	return 0;
}
