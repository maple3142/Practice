#include<iostream>
#include<queue>
using namespace std;

bool g[27][27];
bool vable[27];
queue<int> st;
void dfs(int now){
	vable[now]=false;
	for(int i=1;i<=26;i++){
		if(g[now][i]&&vable[i]){
			dfs(i);
		}
	}
	st.push(now);
}
int main(void){
	ios::sync_with_stdio(false);
	string s,last="nothing";
	while(cin>>s){
		if(s=="#")break;
		if(last=="nothing"){
			last=s;
			continue;
		}
		for(int i=0;i<min(s.length(),last.length());i++){
			vable[s[i]-'A'+1]=vable[last[i]-'A'+1]=true;
			if(s[i]!=last[i]){
				g[s[i]-'A'+1][last[i]-'A'+1]=true;
				break;
			}
		}
		last=s;
	}
	for(int i=1;i<=26;i++){
		if(vable[i])
			dfs(i);
	}
	while(!st.empty()){
		cout<<(char)(st.front()-1+'A');
		st.pop();
	}
	cout<<endl;
	return 0;
}


