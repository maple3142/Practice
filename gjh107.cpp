#include<iostream>
using namespace std;
int p[100001];
int n,k;

bool check(int maxw){
	int thissum=0,times=0;
	for(int i=0;i<n;i++){
		if(p[i]>maxw)
			return false;
		if(thissum<=maxw)
			thissum+=p[i];
		if(thissum>maxw){
			times++;
			thissum=0;
			i--;
		}
	}
	times++;
	//cout<<maxw<<" "<<thissum<<" "<<times<<endl;
	if(times<=k)
		return true;
	return false;
}
int main(void){
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		
		cin>>n>>k;
		int wsum=0;
		for(int j=0;j<n;j++){
			int id,w;
			cin>>id>>w;
			wsum+=w;
			p[id]=w;
		}
		int l = 1,r = wsum,ans;
		while(l<r){
			int mid = (l+r)/2;
			if(check(mid)){
				r = mid;
				ans = mid;
			}
			else 
				l = mid+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}


