#include<iostream>
#include<algorithm>
using namespace std;

int ar[3000];
int main(void){
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>ar[i];
	sort(ar,ar+n);
	int s=0;
	for(int i=0;i<k;i++)
		s+=ar[i];
	cout<<s<<endl;
	return 0;
}

