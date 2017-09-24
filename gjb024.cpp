#include<iostream>
using namespace std; 

unsigned long long int dp[90];
bool a[90];

unsigned long long int cal(int n){
	if(a[n]==true) //已計算的別再算 
		return dp[n-1];
	dp[0]=1;
	dp[1]=2;
	for(int i=2;i<n;i++){
		dp[i]=dp[i-1]+dp[i-2];
		a[i]=true; //標記為已計算 
	}
	return dp[n-1];
}
	
int main(void) {
	int n;
	for(int i=0;i<90;i++)
		a[i]=false;
	while(cin>>n){
		long long int k=cal(n);
		cout<<k<<" "<<cal(k%n)<<endl;
	}
	return 0;
}

