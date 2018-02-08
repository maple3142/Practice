#define local 1
#if local==1
#include<iostream>
using namespace std;
int open[4]={1,1,1,0};
int map[4]={3,1,0,2};
int Initialize(){
	return 4;
}
int tryCombination(const int S[]){
	int mn=0x3f3f3f3f;
	for(int i=0;i<4;i++){
		if(S[i]!=open[i]){
			mn=min(mn,map[i]);
		}
	}
	return mn;
}
int answer(const int S[],const int D[]){
	bool f=true;
	for(int i=0;i<4;i++){
		cout<<"S["<<i<<"]="<<S[i]<<" D["<<i<<"]="<<D[i]<<endl;
		if(S[i]!=open[i]||D[i]!=map[i]){
			f=false;
		}
	}
	if(f)cout<<"OK"<<endl;
}
#else
#include "lib1839.h"
#endif

int cnt[5005];
int ar[5005];
int mp[5005];
bool x;
void chg(int l,int r){
	for(int j=l;j<r;j++){
		if(mp[j]!=-1)continue;
		ar[j]=!ar[j];
	}
}
int search(int l,int r,int prev){
	if(l==r)return l;
	int mid=(l+r)/2,a;
	
	chg(l,mid);
	a=tryCombination(ar);
	x=a>prev;
	if(a!=prev)return search(l,mid,a);
	else return search(mid+1,r,a);
}
int main(void){
	int n=Initialize();
	for(int i=0;i<n;i++)mp[i]=-1;
	for(int i=0;i<n;i++){
		mp[i]=search(0,n,i);
		ar[i]=!x;
	}
	answer(ar,mp);
	return 0;
}
