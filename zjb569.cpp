#include<iostream>
using namespace std;

int main(void){
    string str;
    while(cin>>str>>str){
        string buf;
        for(int i=1;i<str.length();i++)
            buf+=str[i];
        cout<<(str[0]=='0'?1:0)<<buf<<endl;
    }
    return 0;
}
