#include<cstdio>
int dp[10000];
int main(void){
	dp[0]=1;
	int x=0,tmp;
	for(int i=1;i<10000;i++){
		dp[i]=x;
		x=x*2+3*dp[i-1];
	}
	int T;
	scanf("%d",&T);
	for(int u=0;u<T;u++){
		int n;
		scanf("%d",&n);
		printf("%d\n",dp[n]);
	}
	return 0;
}


