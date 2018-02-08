#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<memory.h>
#include<queue>
using namespace std;

const int MOD=1299343;

int st[10];
int ed[10];
int d[MOD];
bool inq[MOD];
int hsh(int ar[]){
	int x=0;
	for(int i=1;i<=8;i++){
		x=x*10+abs(ar[i]);
	}
	return x%MOD;
}
bool prime[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0};
bool ok(int a,int b){
	bool x=prime[abs(a)+abs(b)]&&((a>=0&&b<0)||(b>=0&&a<0));
	return x;
}
int* cp(int ar[]){
	int *x=(int*)malloc(4*10);
	for(int i=1;i<=8;i++){
		x[i]=ar[i];
	}
	return x;
}
int main(void){
	ios::sync_with_stdio(false);
	while(true){
		for(int i=1;i<=8;i++){
			cin>>st[i];
			ed[i]=st[i];
			if(st[1]==0)goto end;
		}
		sort(ed+1,ed+9,[](int a,int b){
			return abs(a)<abs(b);
		});
		
		memset(d,0x3f,sizeof(d));
		memset(inq,0,sizeof(inq));
		
		queue<int*> q;
		q.push(st);
		d[hsh(st)]=0;
		inq[hsh(st)]=true;
		while(!q.empty()){
			int *now=q.front();
			int hnow=hsh(now);
			q.pop();
			inq[hnow]=false;
			
			for(int i=1;i<=8;i++){
				for(int j=i+1;j<=8;j++){
					int a,b;
					if(j+1<=8&&ok(now[i],now[j+1])){
						a=i,b=j+1;
						int *to=cp(now);
						swap(to[a],to[b]);
						int hto=hsh(to);
						if(d[hto]>d[hnow]+1){
							d[hto]=d[hnow]+1;
							if(!inq[hto]){
								q.push(to);
								inq[hto]=true;
							}
						}
					}
					if(j-1>=1&&ok(now[i],now[j-1])){
						a=i,b=j-1;
						int *to=cp(now);
						swap(to[a],to[b]);
						int hto=hsh(to);
						if(d[hto]>d[hnow]+1){
							d[hto]=d[hnow]+1;
							if(!inq[hto]){
								q.push(to);
								inq[hto]=true;
							}
						}
					}
					if(i+1<=8&&ok(now[j],now[i+1])){
						a=j,b=i+1;
						int *to=cp(now);
						swap(to[a],to[b]);
						int hto=hsh(to);
						if(d[hto]>d[hnow]+1){
							d[hto]=d[hnow]+1;
							if(!inq[hto]){
								q.push(to);
								inq[hto]=true;
							}
						}
					}
					if(i-1>=1&&ok(now[j],now[i-1])){
						a=j,b=i-1;
						int *to=cp(now);
						swap(to[a],to[b]);
						int hto=hsh(to);
						if(d[hto]>d[hnow]+1){
							d[hto]=d[hnow]+1;
							if(!inq[hto]){
								q.push(to);
								inq[hto]=true;
							}
						}
					}
					
					
				}
			}
		}
		cout<<d[hsh(ed)]<<endl;
	}
	end:
	return 0;
}

