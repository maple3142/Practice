#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int n,r,c;
	while(cin>>n>>r>>c){
		vector<int> emptyseg,to;
		bool notsameseg=false;
		int flag=1;
		for(int j=0;j<c;j++){
			char c;
			cin>>c;
			if(c=='#'){
				notsameseg=true;
				to.push_back(flag++);
			}
			if(c=='.'){
				if(notsameseg){
					emptyseg.push_back(j);
					notsameseg=false;
				}
			}
		}
		for(int i=1;i<r;i++){
			for(int j=0;j<c;j++){
				char c;
				cin>>c;
				int pos=find(emptyseg.begin(),emptyseg.end(),j)-emptyseg.begin();
				if(pos<emptyseg.size() && c=='#'){
					int temp=to[pos];
					to[pos]=to[pos+1];
					to[pos+1]=temp;
				}
			}
		}
		for(int i=1;i<=to.size();i++){
			int pos=find(to.begin(),to.end(),i)-to.begin();
			cout<<pos+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}


