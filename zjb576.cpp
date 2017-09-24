#include<iostream>
#include<string>
using namespace std;

string dp[30];
string inv(string s){
    for(int i=0;i<s.length();i++)
        s[i]=('4'-s[i])+'0';
    return s;
}
int main(void){
    dp[1]="123";
    for(int i=2;i<29;i++){
        dp[i]=dp[i-1]+inv(dp[i-1]);
    }
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int n;
        cin>>n;
        int rn=n;
        int c=0;
        while(n/2>0){
            n/=2;
            c++;
        }
        cout<<dp[c][rn-1]<<endl;
    }
    return 0;
}
