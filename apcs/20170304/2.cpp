#include<iostream>
using namespace std;

int ar[50005];
bool func(int n,int root){
	if(n<0)return false;
	if(ar[n]==root)return true;
	bool r=func(ar[n],root);
	ar[n]=-1;
	return r;
}
int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>ar[i];
	int cnt=0;
	for(int i=0;i<n;i++){
		if(ar[i]>=0)
			if(func(i,i))
				cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}

