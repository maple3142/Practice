#include<iostream>
#include<bitset>
#include<functional>
#include<unordered_map>
using namespace std;

struct pan{
	int n;
	bool ar[51][51];
	bool operator==(const pan& a)const{
		bool ok=true;
		for(int i=0;i<a.n;i++){
			for(int j=0;j<a.n;j++){
				if(ar[i][j]!=a.ar[i][j]){
					ok=false;
					goto end;
				}
			}
		}
		end:
		return ok;
	}
}now,now90,now180,now270;
namespace std{
	template<>
	struct hash<pan>{
		int operator()(const pan& a)const{
			bitset<2601> b;
			for(int i=1;i<=a.n;i++){
				for(int j=1;j<=a.n;j++){
					if(a.ar[i][j])
						b.set(i*a.n+j);
				}
			}
			//cout<<b<<endl;
			hash<bitset<2601>> fn;
			return fn(b);
		}
	};
}
int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		if(n==0)break;
		now.n=now90.n=now180.n=now270.n=n;
		unordered_map<pan,bool> m;
		bool end=false;
		for(int i=0;i<2*n;i++){
			int a,b;
			char c;
			cin>>a>>b>>c;
			if(!end){
				if(c=='+'){
					now.ar[a][b]=now90.ar[n+1-b][a]=now180.ar[n+1-a][n+1-b]=now270.ar[b][n+1-a]=true;
				}
				else{
					now.ar[a][b]=now90.ar[n+1-b][a]=now180.ar[n+1-a][n+1-b]=now270.ar[b][n+1-a]=false;
				}
				//cout<<m[now]<<" "<<m[now90]<<" "<<m[now180]<<" "<<m[now270]<<endl; 
				if(m[now]||m[now90]||m[now180]||m[now270]){
					cout<<"Player "<<(i%2==0?2:1)<<" wins on move "<<i+1<<endl;
					end=true;
				}
				m[now]=m[now90]=m[now180]=m[now270]=true;
			}
			
			
		}
		if(!end)cout<<"Draw"<<endl;
		now=now90=now180=now270=pan();
	}
	return 0;
}

