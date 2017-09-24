#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

struct road{
	int to;
	double w;
};
struct city{
	vector<road> roads;
	bool vis=false;
}ct[10005];
double d[10005];
int main(void){
	ios::sync_with_stdio(false);
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	for(int i=0;i<m;i++){
		int a,b;
		double c;
		cin>>a>>b>>c;
		ct[a].roads.push_back((road){b,log10(1+c)});
	}
	
	for(int i=1;i<=n;i++)
		d[i]=0x3f3f3f3f;
	int now=s;
	d[now]=0;
	for(int i=0;i<n-1;i++){
		ct[now].vis=true;
		for(road r:ct[now].roads){
			if(!ct[r.to].vis){
				if(d[r.to]>d[now]+r.w){
					d[r.to]=d[now]+r.w;
				}
			}
		}
		double mn=1e9;
		for(int j=1;j<=n;j++){
			if(!ct[j].vis && mn>d[j]){
				mn=d[j];
				now=j;
			}
		}
	}
	double ss=pow(10,d[t]-floor(d[t]));
	cout<<fixed<<setprecision(2)<<ss<<"e+";
	cout<<setw(3)<<setfill('0')<<(int)floor(d[t])<<endl;
	
	//printf("%.2fe+%03d\n",pow(10,ans),floor(d[t])) ;
	return 0;
}

