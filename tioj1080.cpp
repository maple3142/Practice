#include<iostream>
#include<algorithm>
using namespace std;

struct aa{
	int id;
	int val;
	aa(){
		
	}
	bool operator<(const aa& a)const{
		return val<a.val;
	}
};
aa ar[100001];
bool comp(aa a,aa b){
	return a.id<b.id;
}
int BIT[100001];
void upd(int pos,int x){
 for(int i=pos;i<=n;i+=i&(-i))
  BIT[i]+=x;
}
int sum(int x){
 int ans=0;
 for(int i=x;i>0;i-=i&(-i))
  ans+=BIT[i];
 return ans;
}
int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		if(n==0)break;
		for(int i=0;i<n;i++){
			cin>>ar[i].val;
			ar[i].id=i;
		}
		sort(ar,ar+n);
		int c=1,last;
		for(int i=0;i<n;i++){
			if(i>=1&&ar[i].val==last)c--;
			last=ar[i].val;
			ar[i].val=c;
			c++;
		}
		sort(ar,ar+n,comp);
		int ans=0;
	}
	return 0;
}


