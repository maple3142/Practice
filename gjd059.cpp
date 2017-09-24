#include<iostream>
#include<math.h>
using namespace std;

bool p[1000000]={0};
void init(){
    for(int i=2;i<1000000;i++)
        p[i]=true;

    int sq1000000=sqrt(1000000);

    for(int i=2;i<sq1000000;i++){
        if(p[i])
            for(int j=i*i;j<1000000;j+=i)
                p[j]=false;
    }
}
int main(void){
    init();
    int a,b;
    while(cin>>a>>b){
        int f=a,f2=a,count=0;
        bool first=true;
        for(int i=a;i<=b;i++){
            if(p[i]){
                //cout<<i<<" "<<f<<" "<<f2<<endl;
                if(i-f==4 && p[f]){
                    if(first)
                        cout<<"("<<f<<","<<i<<")";
                    else
                        cout<<",("<<f<<","<<i<<")";
                    first=false;
                    f=i;
                    count++;
                }
                else if(i-f2==4 && p[f2]){
                    if(first)
                        cout<<"("<<f2<<","<<i<<")";
                    else
                        cout<<",("<<f2<<","<<i<<")";
                    first=false;
                    f2=i;
                    count++;
                }
                else if(i-f>4)
                    f=i;
                if(i>f2)
                    f2=i;
            }
        }
        cout<<endl<<"共"<<count<<"組"<<endl;
    }
    return 0;
}
