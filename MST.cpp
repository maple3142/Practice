#include<iostream>
#include<algorithm>
using namespace std;


struct edge{
	int l,r,w;
	edge(){
		
	}
	edge(int a,int b,int c){
		l=a;
		r=b;
		w=c;
	}
	bool operator<(const edge &a)const{
		return w<a.w;
	}
};
int par[101];
int findpar(int p){
	if(par[p]==p)return p;
	return par[p] = findpar(par[p]);
}
int main(void){
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int n,m;
		cin>>n>>m;
		edge e[m+1];
		for(int j=1;j<=m;j++){
			int a,b,w;
			cin>>a>>b>>w;
			e[j]=edge(a,b,w);
		}
		for(int j=1;j<=n;j++)
			par[j]=j;
		sort(e+1,e+m+1);
		for(int j=1;j<=m;j++){
			if(findpar(e[j].l)!=findpar(e[j].r)){
				par[findpar(e[j].l)] = findpar(e[j].r);
			}
			if(findpar(1)==findpar(n)){cout<<e[j].w<<endl;break;};
		}
	}
	return 0;
}


