#include<iostream>
#include<algorithm>
using namespace std;

int t[100005];
int ar[100005];
int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++)
			cin>>ar[i];
		int tidx=0;
		t[0]=ar[0];
		for(int i=0;i<n;i++){
			if(t[tidx]<ar[i]){
				t[++tidx]=ar[i];
			}
			else{
				*lower_bound(t,t+tidx,ar[i])=ar[i];
			}
		}
		cout<<tidx+1<<endl;
	}
	return 0;
}


