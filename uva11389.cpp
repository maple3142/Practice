#include<iostream>
#include<algorithm>
using namespace std;

int morn[101],even[101];
int main(void){
	ios::sync_with_stdio(false);
	int n,d,r;
	while(cin>>n>>d>>r){
		if(n==d&&d==r&&r==0)break;
		for(int i=0;i<n;i++)
			cin>>morn[i];
		for(int i=0;i<n;i++)
			cin>>even[i];
		sort(morn,morn+n,[](int a,int b){
			return a<b;
		});
		sort(even,even+n,[](int a,int b){
			return a>b;
		});
		int paid=0;
		for(int i=0;i<n;i++){
			if(morn[i]+even[i]>d)
				paid+=(morn[i]+even[i]-d)*r;
		}
		cout<<paid<<endl;
	}
	return 0;
}

