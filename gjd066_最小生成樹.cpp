#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
//view MST.cpp
map<string,int> code;
map<int,string> uncode;
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
struct edge2{
	int l,r;
	edge2(){
		
	}
	edge2(int a,int b){
		l=a;
		r=b;
	}
	bool operator<(const edge2 &a)const{
		if(l==a.l)return r<a.r;
		return l<a.l;
	}
};
int par[55];
int findpar(int p){
	if(par[p]==p)return p;
	return par[p] = findpar(par[p]);
}
int main(void){
	int n,m;
	while(cin>>n>>m){
		edge e[m+1];
		for(int i=1;i<=n;i++){
			string c;
			cin>>c;
			code[c]=i;
			uncode[i]=c;
		}
		for(int i=1;i<=m;i++){
			string l,f;
			int w;
			cin>>l>>f>>w;
			e[i]=edge(code[l],code[f],w);
		}
		for(int j=1;j<=n;j++)
			par[j]=j;
		sort(e+1,e+m+1);
		int sum=0;
		edge2 connect[55];
		int k=0;
		for(int j=1;j<=m;j++){
			if(findpar(e[j].l)!=findpar(e[j].r)){
				par[findpar(e[j].l)] = findpar(e[j].r);
				sum+=e[j].w;
				connect[k]=edge2(e[j].l,e[j].r);
				k++;
			}
			if(k>=n-1){  
                break;  
            };  
		}
		sort(connect,connect+k);
		for (int i=0;i<k;i++) {
		    cout << "("<<uncode[connect[i].l]<<" "<<uncode[connect[i].r]<<")";
		}
		cout<<endl<<sum<<endl;
		code.clear();
		uncode.clear();
	}
	return 0;
}


