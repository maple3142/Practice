#include<iostream>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;

struct P{
	vector<int> to;
}p[25143];
bool vis[25143];
int prv[25143];
string ar[25143];
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int n=0;
	while(getline(cin,s)){
		if(!s.empty()){
			ar[n++]=s;
		}
		else break;
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(ar[i].length()!=ar[j].length())continue;
			int diff=0;
			string a=ar[i],b=ar[j];
			for(int i=0;i<a.length()&&diff<=1;i++){
				if(a[i]!=b[i])diff++;
			}
			if(diff==1){
				p[i].to.push_back(j);
				p[j].to.push_back(i);
			}
		}
	}
	string a,b;
	int c=0;
	while(cin>>a>>b){
		if(c)cout<<endl;
		int st=-1,ed=-1;
		for(int i=0;i<n&&(st<0||ed<0);i++){
			if(a==ar[i])st=i;
			if(b==ar[i])ed=i;
		}
		queue<int> q;
		q.push(st);
		prv[st]=-1;
		vis[st]=true;
		int lst=-1;
		while(!q.empty()){
			int now=q.front();
			q.pop();
			if(now==ed){
				lst=now;
				break;
			}
			for(int t:p[now].to){
				if(!vis[t]){
					vis[t]=true;
					prv[t]=now;
					q.push(t);
				}
			}
		}
		stack<string> s;
		while(lst!=-1){
			s.push(ar[lst]);
			lst=prv[lst];
		}
		if(s.empty()){
			cout<<"No solution."<<endl;
		}
		while(!s.empty()){
			cout<<s.top()<<endl;
			s.pop();
		}
		memset(vis,0,sizeof(vis));
		c++;
	}
	return 0;
}

