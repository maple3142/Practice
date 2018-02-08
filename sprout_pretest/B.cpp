#include<iostream>
#include<cstring>
using namespace std;

int ar[100];
int scnt[100];
int cnt;
int sort(int n){
	cnt++;
	for(int i=1;i<n;i++){
		for(int j=i;j>0;j--){
			if(ar[j]<ar[j-1]){
				swap(ar[j],ar[j-1]);
				scnt[i]++;
			}
			else
				break;
		}
	}
	int sum=0;
	for(int i=0;i<n;i++){
		ar[i]=scnt[i];
		sum+=scnt[i];
	}
	memset(scnt,0,sizeof(scnt));
	return sum;
}
int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int u=0;u<t;u++){
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>ar[i];
		while(sort(n));
		cout<<cnt<<endl;
		cnt=0;
	}
	return 0;
}


