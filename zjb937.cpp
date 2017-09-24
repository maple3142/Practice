#include<iostream>
#include<unordered_map>
using namespace std;
typedef unsigned long long int ll;

const int MOD=1000000007;
unordered_map<int,ll> player;
ll mx=0,mn=1000000007;
void print(){
	ll a=mx-mn;
	if(a>MOD)
		cout<<a%MOD<<endl;
	else
		cout<<a<<endl;
}
int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		mx=0;
		mn=10000000;
		int mni=0;
		for(int i=1;i<=n;i++){
			cin>>player[i];
			mx=max(mx,player[i]);
			if(mn>player[i]){
				mn=player[i];
				mni=i;
			}
		}
		print();
		int q;
		cin>>q;
		for(int u=0;u<q;u++){
			int a,b;
			cin>>a>>b;
			player[a]*=b;
			mx=max(mx,player[a]);
			if(a==mni){
				mn=player[a];
				for(int i=1;i<=n;i++){
					if(mn>player[i]){
						mn=player[i];
						mni=i;
					}
				}
			}
			print();
		}
		player.clear();
	}
	return 0;
}


