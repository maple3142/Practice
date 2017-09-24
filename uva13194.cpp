#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
typedef long long int ll;

const int MX=1100005;
vector<int> P;
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
int cnt[MX];
int main(void){
	ios::sync_with_stdio(false);
	init();
	int T;
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
		ll nn=n;
		for(int i=0;i<P.size();i++){
			while(nn%P[i]==0){
				nn/=P[i];
				cnt[P[i]]++;
			}
		}
		ll sum=1;
		for(int i=2;i<MX;i++){
			ll s=0;
			if(cnt[i]>0){
				for(int j=0;j<=cnt[i];j++)
					s+=pow(i,j);
				sum*=s;
				//cout<<"sigma "<<i<<"^0~"<<i<<"^"<<cnt[i]<<"="<<s<<endl;
			}
		}
		sum-=n;
		if(sum>n)cout<<"abundant"<<endl;
		else if(sum<n)cout<<"deficient"<<endl;
		else cout<<"perfect"<<endl;
		memset(cnt,0,sizeof(cnt));
	}
	return 0;
}

