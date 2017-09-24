#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

typedef pair<int,int> pii;
int ar[101][101];
int main(void){
	ios::sync_with_stdio(false);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>ar[i][j];
		}
	}
	
	int x,y;
	vector<pii> vx,vy;
	
	for(int i=1;i<=m;i++){
		int sm=0;
		for(int j=1;j<=n;j++){
			sm+=ar[i][j];
		}
		for(int k=0;k<sm;k++)
			vx.push_back(pii(sm,i));
	}
	sort(vx.begin(),vx.end());
	x=vx[vx.size()/2].second;
	
	for(int i=1;i<=n;i++){
		int sm=0;
		for(int j=1;j<=m;j++){
			sm+=ar[j][i];
		}
		for(int k=0;k<sm;k++)
			vy.push_back(pii(sm,i));
	}
	sort(vy.begin(),vy.end());
	y=vy[vy.size()/2].second;
	
	cout<<x<<" "<<y<<endl;
	return 0;
}

