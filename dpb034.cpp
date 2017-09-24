#include<iostream>  
using namespace std;  
  
int coins[9] = {1,5,10,50,100,500,1000,5000,10000};   
int dp[100000];  
int num;  
  
int min(int a,int b)  
{  
    return (a<=b)? a:b;  
}  
  
void mcoins(int i)  
{  
    if(i==0){  
        dp[i]=0;  
        mcoins(1);  
        return;  
    }  
    else{  
        int MIN=100;  
        for(int j=0;j<9;j++){ //測試硬幣表中是否有能用的   
            if(i>=coins[j]){  
                MIN=min(MIN,dp[i-coins[j]]+1);  
                //cout<<i<<" "<<coins[j]<<" "<<MIN<<endl;  
            }  
        }  
        dp[i]=MIN;  
        if(i==num)  
            return;  
        else  
            mcoins(i+1);  
    }  
}  
  
int main(void){  
    while(cin>>num){  
        mcoins(0);  
        cout<<dp[num]<<endl;  
    }  
    return 0;  
}  
