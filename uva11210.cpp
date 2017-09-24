#include<iostream>
#include<cstring>
using namespace std;

string mahjong[]={
	"1T","2T","3T","4T","5T","6T","7T","8T","9T",
	"1S","2S","3S","4S","5S","6S","7S","8S","9S",
	"1W","2W","3W","4W","5W","6W","7W","8W","9W",
	"DONG","NAN","XI","BEI",
	"ZHONG","FA","BAI"
};
int tiles[34];
bool search(int dep){
	for(int i=0;i<34;i++){
		if(tiles[i]>=3){
			if(dep==3)return true;
			tiles[i]-=3;
			if(search(dep+1)){
				tiles[i]+=3;
				return true;
			}
			tiles[i]+=3;
		}
	}
	for(int i=0;i<24;i++){
		if(i%9<=6&&tiles[i]>=1&&tiles[i+1]>=1&&tiles[i+2]>=1){
			if(dep==3)return true;
			tiles[i]--;
			tiles[i+1]--;
			tiles[i+2]--;
			if(search(dep+1)){
				tiles[i]++;
				tiles[i+1]++;
				tiles[i+2]++;
				return true;
			}
			tiles[i]++;
			tiles[i+1]++;
			tiles[i+2]++;
		}
	}
	return false;
}
bool check(){
	for(int i=0;i<34;i++){
		if(tiles[i]>=2){
			tiles[i]-=2;
			if(search(0)){
				tiles[i]+=2;
				return true;
			}
			tiles[i]+=2;
		}
	}
	return false;
}
int main(void){
	ios::sync_with_stdio(false);
	int cse=1;
	string s;
	while(cin>>s){
		if(s=="0")break;
		cout<<"Case "<<cse++<<":";
		for(int i=0;i<34;i++){
			if(mahjong[i]==s)tiles[i]++;
		}
		for(int i=1;i<13;i++){
			cin>>s;
			for(int j=0;j<34;j++){
				if(mahjong[j]==s)tiles[j]++;
			}
		}
		/*for(int i=0;i<34;i++){
			cout<<mahjong[i]<<": "<<tiles[i]<<endl;
		}*/
		bool ready=false;
		for(int i=0;i<34;i++){
			if(tiles[i]>=4)continue;
			tiles[i]++;
			if(check()){
				ready=true;
				cout<<" "<<mahjong[i];
			}
			tiles[i]--;
		}
		if(!ready)cout<<" Not ready";
		cout<<endl;
		memset(tiles,0,sizeof(tiles));
	}
	return 0;
}

