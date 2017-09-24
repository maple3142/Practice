#include<iostream>
using namespace std;

int ar[3]={1,2,0};
int idx=0;
void print(){
	cout<<ar[idx++];
	idx%=3;
}
int main(void){
	ios::sync_with_stdio(false);
	
	int n;
	while(cin>>n){
		if(n>=1)cout<<1<<endl;
		if(n>=2)cout<<20<<endl;
		if(n>=3){
			int a=1,b=2;
			for(int j=0;j<n-2;j++){
				for(int i=0;i<a+b;i++){
					print();
				}
				int tmp=b;
				b=a+b;
				a=tmp;
				cout<<endl;
			}
			
		}	
	}
	return 0;
}


