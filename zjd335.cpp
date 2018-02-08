#include<iostream>
#include<unordered_map>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int,int> pii;

const int MX=105;

string ctump[MX];
unordered_map<string,int> ctmp;
int ctcnt=0;
int ct2id(string s){
	if(ctmp.count(s)==0){
		ctcnt++;
		ctmp[s]=ctcnt;
		ctump[ctcnt]=s;
	}
	return ctmp[s];
}

vector<pii> E;
bool ok[MX][MX];
bool inq[MX];
int d[MX][MX];
int nxt[MX][MX];
void floyd(){
	memset(d,0x3f,sizeof(d));
	memset(nxt,0,sizeof(nxt));
	for(pii e:E){
		d[e.first][e.second]=d[e.second][e.first]=1;
		nxt[e.first][e.second]=e.second;
	}
	for(int k=1;k<=ctcnt;k++){
		for(int i=1;i<=ctcnt;i++){
			for(int j=1;j<=ctcnt;j++){
				if(d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k]+d[k][j];
					nxt[i][j]=nxt[i][k];
				}
			}
		}
	}
}
vector<int> getPath(int a,int b){
	
	if(nxt[a][b]==0)return vector<int>({a,b});
	vector<int> v({a});
	while(a!=b){
		a=nxt[a][b];
		v.push_back(a);
	}
	return v;
}
int main(void){
	ios::sync_with_stdio(false);
	int T,kase=1;
	cin>>T;
	while(T--){
		if(kase++>1)cout<<endl;
		int m,n;
		cin>>m>>n;
		string a,b;
		int aa,bb;
		while(m--){
			cin>>a>>b;
			aa=ct2id(a);
			bb=ct2id(b);
			E.emplace_back(aa,bb);
			E.emplace_back(bb,aa);
		}
		floyd();
		while(n--){
			cin>>a>>b;
			aa=ct2id(a);
			bb=ct2id(b);
			vector<int> p=getPath(aa,bb);
			for(int x:p){
				cout<<ctump[x][0];
			}
			cout<<endl;
		}
		
		ctcnt=0;
		E.clear();
		ctmp.clear();
	}
	return 0;
}

