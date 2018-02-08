#include<iostream>
#include<algorithm>
using namespace std;

int N,M;
bool dfs2(vector<int> v,int m){
	if(m==M)return true;
	for(int i=0;i<v.size()-2;i++){
		if(v[i]==v[i+1]&&v[i]==v[i+2]){
			int tmp=v[i];
			v.erase(v.begin()+i);
			bool r=dfs2(v,m+1);
			if(r)return true;
			v.push_back(tmp);
			v.push_back(tmp);
			v.push_back(tmp);
		}
	}
	for(int i=0;i<v.size()-2;i++){
		if(v[i]==v[i+1]-1&&v[i]==v[i+2]-2){
			int tmp=v[i];
			v.erase(v.begin()+i);
			bool r=dfs2(v,m+1);
			if(r)return true;
			v.push_back(tmp);
			v.push_back(tmp+1);
			v.push_back(tmp+2);
		}
	}
	return false;
}
bool dfs1(vector<int> v){
	for(int i=0;i<v.size()-1;i++){
		if(v[i]==v[i+1]){
			int tmp=v[i];
			v.erase(v.begin()+i);
			bool r=dfs2(v,0);
			if(r)return true;
			v.push_back(tmp);
			v.push_back(tmp);
		}
	}
	return false;
}
bool test(vector<int> v,int x){
	v.push_back(x);
	sort(v.begin(),v.end());
	return dfs1(v);
}
int main(void){
	ios::sync_with_stdio(false);
	cin>>N>>M;
	vector<int> v;
	int x;
	for(int i=1;i<=3*M+1;i++){
		cin>>x;
		v.push_back(x);
	}
	int cnt=0;
	for(int i=1;i<=N;i++){
		if(test(v,i)){
			cout<<i<<' ';
			cnt++;
		}
	}
	if(cnt==0)cout<<"No"<<
	cout<<endl;
	return 0;
}

