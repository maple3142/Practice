#include<iostream>
using namespace std;
typedef long long int ll;

ll dp[95][16];
int n,m;
ll bk(int idx,int lt){
	if(idx==m)return 1;
	ll sum=0;
	if(lt<n){
		if(!dp[idx+1][lt+1])
			dp[idx+1][lt+1]=bk(idx+1,lt+1);
		sum+=dp[idx+1][lt+1];
	}
	sum+=bk(idx+1,0);
	return sum;
}
int main(void){
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	cout<<bk(0,0)<<endl;
	return 0;
}

