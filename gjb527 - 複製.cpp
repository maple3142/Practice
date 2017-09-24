#include<iostream>
using namespace std;

int m,ar[20],s=0;
bool used[20];
bool finded=false;
void find(int now,int d){
	if(finded)return;
	if(d>s/2)return;
	if((s%10007)==(2*d%10007)){
		finded=true;
		return;
	}
	for(int i=now;i<m;i++){
		if(used[i])continue;
		used[i]=true;
		find(now+1,(d+ar[i])%10007);
		used[i]=false;
	}
}
int main(void){
	while(cin>>m){
		for(int i=0;i<m;i++){
			cin>>ar[i];
			s+=ar[i];
		}
			
		find(0,0);
		cout<<(finded?"YES":"NO")<<endl;
		finded=false;
		s=0;
	}
	return 0;
}


