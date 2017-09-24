#include<iostream>  
using namespace std;  
  
int len[101],stf[101];  
int dp[2][1001];  
int main(void){  
    ios::sync_with_stdio(false);  
    int n,m;  
    cin>>n>>m;  
    for(int i=1;i<=n;i++){  
        cin>>len[i]>>stf[i];  
    }  
    for(int i=1;i<=n;i++){  
        for(int v=0;v<=m;v++){  
            dp[i%2][v]=max(dp[(i+1)%2][v],(v-len[i]>=0?dp[(i+1)%2][v-len[i]]+stf[i]:0));  
        }  
    }  
    cout<<dp[n%2][m]<<endl;  
    return 0;  
}
