#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;

int ar[100005];
int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		if(n==0)break;
		for(int i=0;i<n;i++)
			cin>>ar[i];
		sort(ar,ar+n);
		ll floors=2;
		int down=0;
		for(int i=0;i<n;i++){
			floors+=max(ar[i],down);
			down=ar[i]-1;
		}
		floors+=down;
		cout<<floors<<endl;
	}
	return 0;
}


