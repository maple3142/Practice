#include<iostream>
#include<vector>
using namespace std;
typedef long long int ll;

vector<int> v;
ll merge(ll l,ll r){ //[l,r)
	if(l==r-1)return 0;
	int mid=(l+r)/2;
	ll cnt=0;
	cnt+=merge(l,mid);
	cnt+=merge(mid,r);
	ll tmp[r-l];
	
	ll rcnt=0;
	ll li=l,ri=mid;
	for(int i=0;i<r-l;i++){
		if((v[li]>v[ri] || li==mid) && ri!=r){
			tmp[i]=v[ri];
			rcnt++;
			ri++;
		}
		else if(li!=mid){
			tmp[i]=v[li];
			li++;
			cnt+=rcnt;
		}
	}
	for(int i=0;i<r-l;i++)v[l+i]=tmp[i];
	return cnt;
}
int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		if(n==0)break;
		int x;
		for(int i=0;i<n;i++){
			cin>>x;
			v.push_back(x);
		}
		cout<<merge(0,n)<<endl;
		v.clear();
	}
	return 0;
}

