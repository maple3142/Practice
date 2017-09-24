#include<iostream>
using namespace std;

long long int cal(int x,int y){
		long long int dp[x+1][y+1];
		//加入邊界
		for(int i=0;i<=x;i++) 
			dp[i][0]=0;
		for(int i=1;i<=y;i++)
			dp[0][i]=0;
		
		for(int i=1;i<=x;i++){
			for(int j=1;j<=y;j++){
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
				if(i==1 && j==1)
					dp[1][1]=1;
			}
		}
		return dp[x][y];
	}

int main(void) {
		int x,y;
		while(cin>>x>>y){
			x++;
			y++;
			cout<<cal(x,y)<<endl;
		}
		return 0;
	}
	
	


