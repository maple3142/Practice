#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;

pii ar[101];
int main(void){
	ios::sync_with_stdio(false);
	int n,sum=0,tmp;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp;
		ar[i]=pii(tmp,i+1);
		sum+=tmp;
	}
	sort(ar,ar+n);
	for(int i=0;i<n/2;i++){
		cout<<ar[i].second<<' '<<ar[n-i-1].second<<endl;
	}
	return 0;
}

