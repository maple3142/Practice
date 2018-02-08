#include<iostream>
#include<vector>
using namespace std;

int main(void){
    string s1,s2;
    while(cin>>s1>>s2){
        int n,k;
        cin>>n>>k;
        vector<string> d;
        d.push_back(s1);
        d.push_back(s2);
        for(int i=2;i<n;i++){
            d.push_back(d[i-1]+d[i-2]);
        }
        if(d[n-1][k-1])
            cout<<d[n-1][k-1]<<endl;
        else
            cout<<"x"<<endl;
    }
    return 0;
}
