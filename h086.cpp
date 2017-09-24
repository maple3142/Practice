#include<iostream>
#include<vector>
#include<map>
//#include<iterator>
using namespace std;

int n,m;
bool yes=false;
vector<int> v1[8];
vector<int> v2[8];
bool vis[8]={0};
int ar[8]={0};
bool equal(){
	bool tmp;
	for(int i=0;i<n;i++){
		for(int j=0;j<v1[i].size();j++){
			tmp=false;
			for(int k=0;k<v2[ar[i]].size();j++){
				if(v1[i][j]==v2[ar[i]][k]){tmp=true;break;}
			}
			if(!tmp){return false;}
		}
	}
}

void backtracking(int now){
	cout<<now<<endl;
	if(now >= n){
		for(int i=0;i<n;i++){
			cout<<ar[i]<<" ";
		}
		cout<<endl;
		yes=equal();
	}
	for(int i=0;i<n;i++){
		if(vis[i])continue;
		vis[i] = true;
		ar[now] = i;
		backtracking(now+1);
		vis[i] = false;
	}
}
void input1(){
	map<int,int> mp;
	for(int i=0;i<m;i++){
		char a,b;
		cin>>a>>b;
		mp[(int)a-'A']=(int)b-'A';
	}
	map<int,int>::iterator it;
	for(it=mp.begin();it != mp.end();++it){
    	cout<<*it<<endl;
  	} 
}
int main(void){
	int T;
	cin>>T;
	for(int k=0;k<T;k++){
		yes=false;
		vis[8]={0};
		ar[8]={0};
		cin>>n>>m;
		for(int i=0;i<m;i++){
			char a,b;
			cin>>a>>b;
			v1[a-'A'].push_back(b-'A');
			v1[b-'A'].push_back(a-'A');
		}
		for(int i=0;i<m;i++){
			char a,b;
			cin>>a>>b;
			v2[a-'a'].push_back(b-'a');
			v2[b-'a'].push_back(a-'a');
		}
		
		backtracking(0);
		cout<<(yes?"yes":"no")<<endl;
	}
	return 0;
}


