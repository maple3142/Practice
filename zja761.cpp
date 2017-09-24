#include<iostream>
using namespace std;

int mem[101];
int main(void){
	ios::sync_with_stdio(false);
	string s;
	while(cin>>s){
		if(s=="map"){
			int reg,a,b;
			cin>>reg>>a>>b;
			int minconflict=0;
			for(int i=a;i<=b;i++){
				if(mem[i]){
					if(minconflict!=0)
						minconflict=min(minconflict,mem[i]);
					else
						minconflict=mem[i];
				}
			}
			if(!minconflict){
				for(int i=a;i<=b;i++){
					mem[i]=reg;
				}
				cout<<"region "<<reg<<" created"<<endl;
			}
			else
				cout<<"fail to create region "<<reg<<", overlap with region "<<mem[minconflict]<<endl;
		}
		if(s=="load"){
			int c;
			cin>>c;
			if(!mem[c])
				cout<<"fail to load from "<<c<<endl;
			else
				cout<<"load from region "<<mem[c]<<endl;
		}
		if(s=="store"){
			int c;
			cin>>c;
			if(!mem[c])
				cout<<"fail to store to "<<c<<endl;
			else
				cout<<"store to region "<<mem[c]<<endl;
		}
	}
	return 0;
}


