#include<iostream>
using namespace std;

int main(void){
    string yee;
    while(cin>>yee){
        int b=0,y=0;
        for(int i=0;i<yee.length();i++){
				if(yee[i]=='y'){
					b+=((i-y)>0?i-y:y-i);
					y+=3;
				}
			}
        cout<<b<<endl;
    }
    return 0;
}
