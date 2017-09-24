#include<iostream>
#include<string>
using namespace std;

int main(void){
	string map,hit;
	while(cin>>map>>hit){
		int score=0,combo=0,soul=0,mxcombo=0;
		for(int i=0;i<map.length();i++){
			if(map[i]==hit[i] && map[i]!='-'){
				combo++;
				score+=combo*100;
				soul++;
			}
			else if(map[i]!='-'){
				if(combo>mxcombo)
					mxcombo=combo;
				combo=0;
				soul-=3;
				if(soul<0)soul=0;
			}
		}
		if(combo>mxcombo)
			mxcombo=combo;
		cout<<score<<" "<<mxcombo<<" "<<soul<<endl;
	}
	return 0;
}


