#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ar[4010];
int main(void){
	ios::sync_with_stdio(false);
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		int tmp;
		for(int i=0;i<n;i++){ //123->321123
			cin>>tmp;
			ar[n+i]=ar[n-i-1]=tmp;
		}
		vector<int> v;
		v.push_back(ar[0]);
		for(int i=1;i<n*2;i++){
			if(ar[i]>v.back()){
				v.push_back(ar[i]);
			}
			else{
				*lower_bound(v.begin(),v.end(),ar[i])=ar[i];
			}
		}
		cout<<min((int)v.size(),n)<<endl;
	}
	return 0;
}
