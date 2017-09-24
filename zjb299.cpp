#include<iostream>
using namespace std;

int main(void){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        bool can=true;
        int w,rq;
        cin>>w>>rq;
        for(int j=0;j<rq;j++){
            int b;
            cin>>b;
            if(w>b)
                can=false;
        }
        cout<<(can?"YEEES!!! INKER!":"NOOOO!!! JACKY XX!")<<endl;
    }
    return 0;
}
