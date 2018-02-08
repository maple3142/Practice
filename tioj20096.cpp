#include<iostream>
#include<algorithm>
using namespace std;

int N,M;
bool dfs2(vector<int> v,int m){
	vector<vector::iterator> iters[401];
	for(auto it=v.begin();it!=v.end();it++){
		iters[*it].push_back(it);
		if(iters.size()==3){
			for(int i=0;i<3;i++){
				v.erase(iters[*it][i]);
			}
			bool r=dfs2(v,m+1);
			if(r)return true;
			v.push_back(*it);
			v.push_back(*it);
		}
	}
}
bool dfs1(vector<int> v){
	vector<vector::iterator> iters[401];
	for(auto it=v.begin();it!=v.end();it++){
		iters[*it].push_back(it);
		if(iters.size()==2){
			for(int i=0;i<2;i++){
				v.erase(iters[*it][i]);
			}
			bool r=dfs2(v,0);
			if(r)return true;
			v.push_back(*it);
			v.push_back(*it);
		}
	}
	return false;
}
int test(vector<int> v,int x){
	v.push_back(x);
	sort(v.begin(),v.end());
	
}
int main(void){
	ios::sync_with_stdio(false);
	
	return 0;
}

