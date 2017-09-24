#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int ar[1001];
int n;
int find(int arr[]){
	for(int d=n-1;d>=0;d--)
		for(int a=0;a<n;a++)
			for(int b=a+1;b<n;b++)
				for(int c=b+1;c<n;c++){
					if(a!=d&&b!=d&&c!=d&&arr[a]+arr[b]+arr[c]==arr[d])
						return arr[d];
				}
	return -0x3f3f3f3f;
}
int main(void){
	ios::sync_with_stdio(false);
	while(cin>>n){
		if(n==0)break;
		for(int i=0;i<n;i++){
			cin>>ar[i];
		}
		sort(ar,ar+n);
		int mx=find(ar);
		if(mx==-0x3f3f3f3f)
			cout<<"no solution"<<endl;
		else
			cout<<mx<<endl;	
		
	}
	return 0;
}

