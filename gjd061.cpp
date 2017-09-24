#include<iostream>
using namespace std;

bool isloop(string s){
    for(int i=0;i<s.length()/2;i++)
        if(s[i]!=s[s.length()-1-i])
            return false;
    return true;
}
string substring(string s,int f,int t){
    string buf;
    for(int i=f;i<t;i++)
        buf+=s[i];
    return buf;
}
int main(void){
    int n;
    while(cin>>n){
        string str[n];
        for(int i=0;i<n;i++)
            cin>>str[i];
        for(int k=0;k<n;k++){
            int mx=0,mxsc=0;
            string mxs[10];
            for(int i=0;i<str[k].length();i++){
                for(int j=i+1;j<str[k].length();j++){
                    cout<<i<<" "<<j<<" "<<substring(str[k],i,j)<<" "<<isloop(substring(str[k],i,j))<<endl;
                    if(isloop(substring(str[k],i,j)));
                        if(j-i>mx){
                            mx=j-i-1;
                            mxs[mxsc]=substring(str[k],i,j);
                            mxsc++;
                        }
                        if(j-i==mx){
                            mxs[mxsc]=substring(str[k],i,j);
                            mxsc++;
                        }

                }
            }
            cout<<"第"<<k+1<<"組測試資料的最長迴文子字串長度為:"<<mx<<endl;
            cout<<"第"<<k+1<<"組測試資料的最長迴文子字串內容為:";
            for(int i=0;i<mxsc;i++){
                cout<<mxs[i];
                if(i!=mxsc-1)
                    cout<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
