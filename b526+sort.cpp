#include<iostream>
#include<queue> 
#include <algorithm>
#include <cstring>
using namespace std;
struct M{
	int l,r;
	M(){
		
	}
	bool operator<(const M &a)const{
		if(l == a.l)return r<a.r;
		return l<a.l;
	}
};
int main(void){
	int n,m,sum=0;
	cin>>n>>m;
	M g[m];
	priority_queue<int> q;
	for(int i=0;i<m;i++){
		cin>>g[i].l>>g[i].r;
		
	}
	sort(g,g+m);
	int rc=0,i=0;
	for(;i<m;i++){
		//cout<<q.top().l<<q.top().r<<endl;
		//q.pop();
		while(!q.empty()){
			if( (q.top()*-1) >= g[i].l ){ //qtop¥k¬É>qil¥ª¬É 
				if(rc%2==0)
					sum+=g[i].l-g[i-1].l;
				break;
			}
			else if( (q.top()*-1) < g[i].l ){
				if(rc%2==1)
					sum+=g[i].l-(q.top()*-1)+1;
				q.pop();
				rc--;
			}
		}
		q.push(g[i].r*-1);
		rc++;
	}
	while(!q.empty()){
		if( (q.top()*-1) >= g[i-1].l ){
			if(rc%2==0)
				sum+=g[i].l-(q.top()*-1)+1;
			q.pop();
		}
	}
	cout<<sum<<endl;
	return 0;
}


