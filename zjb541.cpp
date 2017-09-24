#include<iostream>
#include<string>
using namespace std;

string dp[41];
int main(void){
    dp[1]="1";
    for(int i=2;i<41;i++){
        string buf;
        int count=0;
        char current='\0';
        for(int c=0;c<dp[i-1].length();c++){
            if(dp[i-1][c]!=current){
                if(count!=0){
                    dp[i]+=to_string(count);
                    dp[i]+=current;
                }
                current=dp[i-1][c];
                count=1;
            }
            else
                count++;
        }
        if(count!=0){
            dp[i]+=to_string(count);
            dp[i]+=current;
        }
    }
    int n;
    while(cin>>n){
        cout<<dp[n]<<endl;
    }
    return 0;
}
