#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_map>
using namespace std;
typedef long long int ll;

const int MX=3000000;
vector<ll> P;
bool prime[MX];
void init(){
	for(int i=0;i<MX;i++)
		prime[i]=true;
	prime[0]=prime[1]=false;
	for(int i=2;i<sqrt(MX);i++){
		if(prime[i]){
			for(int j=i+i;j<MX;j+=i){
				prime[j]=false;
			}
		}
	}
	for(int i=0;i<MX;i++){
		if(prime[i]){
			P.push_back(i);
		}
	}
}
int main(void){
	ios::sync_with_stdio(false);
	init();
	ll n;
	while(cin>>n){
		if(n==0){
			cout<<0<<endl;
			continue;
		}
		ll nn=n;
		unordered_map<ll,ll> m;
		for(ll i:P){
			if(i>n)break;
			while(n%i==0){
				if(i!=2)m[i]++;
				n/=i;
			}
		}
		if(n>1)m[n]++;
		n=nn;
		ll sum=1;
		for(auto e:m){
			sum*=e.second+(ll)1;
		}
		cout<<sum<<endl;
	}
	return 0;
}

