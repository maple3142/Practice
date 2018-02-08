#include<iostream>
#include<vector>
#include<utility>
using namespace std;
typedef pair<int,int> pii; //destination,weight

vector<pii> ar[26];
int dfs(int now,int sum=0){
	int mx=sum;
	for(pii p:ar[now]){
		mx=max(dfs(p.first,sum+p.second),mx);
	}
	return mx;
}
int main(void){
	ios::sync_with_stdio(false);
	char s; //start
	cin>>s;
	s-='A';
	char a,b;
	int n,c;
	cin>>n;
	while(n--){
		cin>>a>>b>>c;
		a-='A';
		b-='A';
		ar[a].push_back(pii(b,c));
	}
	cout<<dfs(s)<<endl;
	return 0;
}

