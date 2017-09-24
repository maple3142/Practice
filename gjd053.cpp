#include<iostream>
using namespace std;

int main(void){
    long n;
    while(cin>>n){
        long i=2;
        cout<<n<<" = ";
        bool first=true;
        while(i<=n){
            while(n%i==0){
                n/=i;
                if(!first)
                    cout<<" * "<<i;
                else
                    cout<<i;
                first=false;
            }
            i++;
        }
        cout<<endl;
    }
    return 0;
}
