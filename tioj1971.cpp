#include<iostream>
using namespace std;

int ar[21];
bool b[100000005];
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m,n;
	cin>>m>>n;
	int mn=0x3f3f3f3f;
	for(int i=0;i<n;i++){
		cin>>ar[i];
		mn=min(mn,ar[i]);
	}
	int c=0;
	for(int i=mn;i<=m;i++){
		bool x=false;
		for(int j=0;j<n;j++){
			if(i-ar[j]<0)continue;
			if(!b[i-ar[j]]){
				x=true;
				break;
			}
		}
		if(x&&i>0){
			b[i]=true;
			c++;
		}
	}
	cout<<c<<endl;
	return 0;
}

