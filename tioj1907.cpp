#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct mypair{
	int id,w,h;
	mypair(){
		
	}
	mypair(int c,int d,int e){
		id=c;
		w=d;
		h=e;
	}
	bool operator<(const mypair& a)const{
		if(w==a.w)
			return h>a.h;
		return w<a.w;
	}
};
mypair war[20001];
int ar[20001];
int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int u=0;u<t;u++){
		int m;
		cin>>m;
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			war[i]=mypair(i,x,y);
		}
		sort(war,war+m);
		int idx=1;
		for(int i=0;i<m;i++){
			if(ar[idx-1]<war[i].h){
				ar[idx++]=war[i].h;
			}
			else{
				int* p=lower_bound(ar+1,ar+idx,war[i].h);
				*p=war[i].h;
			}
		}
		cout<<idx-1<<endl;
		memset(ar,0,sizeof(ar));
	}
	return 0;
}


