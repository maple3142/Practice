#include"lib1227.h"

long long *p,n;
long long ch[1000005];
void init(int N, long long D[]){
	n=N;
	p=D;
}
void change(int a,int b, long long k){
	ch[a]+=k*(a%2==0?-1:1);
	ch[b+1]+=k*(a%2==1?-1:1);
}
bool run=false;
void build(){
	long long x=0;
	for(int i=0;i<n;i++){
		x+=ch[i];
		p[i]+=x*(i%2==1?-1:1);
	}
}
long long query(int c){
	if(!run){
		build();
		run=true;
	}
	return p[c];
}
