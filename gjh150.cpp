#include<iostream>
using namespace std;

int main(void){
	int q;
	cin>>q;
	int n[q];
	for(int i=0;i<q;i++)
		cin>>n[i];
	
	for(int i=0;i<q;i++){
		long zero=0,ans;
		for(long j=5;true;j+=5){
			long fcount=0,tmp=j;
			while(tmp%5==0){
				tmp/=5;
				fcount++;
			}
			zero+=fcount;
			if(zero==n[i]){
				ans=j;
				break;
			}
			else if(zero>n[i]){
				ans=-1;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


