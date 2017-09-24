#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main(void){
    double a;
    while(cin>>a){
        a=(acos(asin(a))*180)/M_PI;
        if(to_string(a)=="nan")
            cout<<"FAIL!"<<endl;
        else
            cout<<fixed<<setprecision(2)<<a<<endl;
    }
    return 0;
}
