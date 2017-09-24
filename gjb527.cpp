#include<iostream>
using namespace std;

int m,ar[20];
bool used[20];
bool finded=false;
void find(int now,int d1,int d2){
	if(finded)return;
	if(now==m && d1==d2 && d1!=0){
		finded=true;
		return;
	}
	for(int i=now;i<m;i++){
		if(used[i])continue;
		used[i]=true;
		find(now+1,d1+ar[i],d2);
		find(now+1,d1,d2+ar[i]);
		used[i]=false;
	}
}
int main(void){
	while(cin>>m){
		for(int i=0;i<m;i++)
			cin>>ar[i];
		find(0,0,0);
		cout<<(finded?"YES":"NO")<<endl;
		finded=false;
	}
	return 0;
}


