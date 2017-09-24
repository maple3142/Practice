#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

const int MX=1000001;
int row[MX],col[MX];
vector<vector<int>> ar;
int main(void){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		row[i]=i;
	for(int i=1;i<=n;i++)
		col[i]=i;
		
	ar.push_back(vector<int>());
	string s;
	for(int i=1;i<=m;i++){
		vector<int> v;
		v.push_back(0);
		for(int j=1;j<=n;j++){
			cin>>s;
			v.push_back(stoi(s.substr(1,s.length()),nullptr,16));
		}
		ar.push_back(v);
	}
	
	int p;
	cin>>p;
	while(p--){
		char a;
		cin>>a;
		if(a=='S'){
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			swap(ar[row[x1]][col[y1]],ar[row[x2]][col[y2]]);
		}
		if(a=='R'){
			int x,y;
			cin>>x>>y;
			swap(row[x],row[y]);
		}
		if(a=='C'){
			int x,y;
			cin>>x>>y;
			swap(col[x],col[y]);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cout<<'#'<<uppercase<<setfill('0')<<setw(6)<<hex<<ar[row[i]][col[j]]<<" ";
		}
		cout<<'\n';
	}
	cout.flush();
	return 0;
}

