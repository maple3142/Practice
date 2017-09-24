#include<iostream>
#include<sstream>
#include<vector>
#include<cstring>
#include<limits>
#include<algorithm>
using namespace std;

int T[6];
int dis[100][6];
vector<int> elev[6];
int main(void){
	ios::sync_with_stdio(false);
	int n,k;
	while(cin>>n>>k){
		for(int i=1;i<=n;i++)
			cin>>T[i];
		cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
		for(int i=1;i<=n;i++){
			string s;
			getline(cin,s);
			istringstream ss(s);
			string tk;
			while(getline(ss,tk,' ')){
				elev[i].push_back(stoi(tk));
			}
		}
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=5;i++)
			dis[0][i]=0;
		
		for(int i=0;i<100;i++){
			for(int j=1;j<=5;j++){
				vector<int> ex=elev[j];
				if(find(ex.begin(),ex.end(),j)==ex.end())continue;
				for(int fr:elev[j]){
					dis[i][j]=min(dis[i][j],dis[fr][j]+(i-fr)*T[j]);
				}
				for(int ev=1;ev<=5;ev++){
					if(ev==j)continue;
					vector<int> ex=elev[ev];
					if(find(ex.begin(),ex.end(),ev)!=ex.end())
						dis[i][j]=min(dis[i][j],dis[i][ev]+60);
				}
				cout<<"floor: "<<i<<" elev: "<<j<<" "<<dis[i][j]<<endl;
			}
		}
		int mn=0x3f3f3f3f;
		for(int i=1;i<=5;i++){
			mn=min(mn,dis[k][i]);
		}
		cout<<mn<<endl;
	}
	return 0;
}

