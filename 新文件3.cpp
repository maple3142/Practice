#include<iostream>
#include<vector>
using namespace std;

int n,s,k;
const int user=11111;
const int server=22222;
const int vod=33333;
struct Node{
	int type;
	bool ok;
	vector<int> to;
	Node(){
		ok=false;
		type=server;
	}
};
Node ar[1001];
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>s>>k;
		ar[s].type=vod;
		for(int i=0;i<n-1;i++){
			int a,b;
			ar[a].to.push_back(b);
			ar[b].to.push_back(a);
		}
		for(int i=1;i<=n;i++){
			if(ar[i].to.size()==1)
				ar[i].type=user;
		}
		
	}
	return 0;
}

