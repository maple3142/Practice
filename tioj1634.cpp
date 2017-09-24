#include<iostream>
#include<cmath>
using namespace std;

int ar[30];
int main(void){
	ios::sync_with_stdio(false);
	int k;
	cin>>k;
	for(int i=0;i<=k;i++){
		cin>>ar[i];
	}
	int s=ar[0],i;
	for(i=1;i<=k;i++){
		if(s<pow(2,i)-1){
			cout<<s+1<<endl;
			break;
		}
		else{
			s+=ar[i]*pow(2,i);
		}
	}
	if(i>k){
		cout<<s+1<<endl;
	}
	return 0;
}

