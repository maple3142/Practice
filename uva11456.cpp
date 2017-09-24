#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ar[4034];
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n==0){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<n;i++){
			cin>>ar[n+i];
			ar[n-i-1]=ar[n+i];
		}
		vector<int> v;
		v.push_back(ar[0]);
		for(int i=1;i<n+n;i++){
			if(ar[i]>v.back()){
				v.push_back(ar[i]);
			}
			else{
				*lower_bound(v.begin(),v.end(),ar[i])=ar[i];
			}
		}
		cout<<v.size()<<endl;
	}
	return 0;
}

