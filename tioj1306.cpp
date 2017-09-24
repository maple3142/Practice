#include<iostream>
#define m 1000000007
using namespace std;
typedef long long int ll;

ll p[10001];
int main(void){
	ios::sync_with_stdio(false);
	p[0]=1;
	for(int i=1;i<=10000;i++){
		p[i]=p[i-1]*26%m;
	}
	int t;
	cin>>t;
	for(int u=0;u<t;u++){
		string b;
		cin>>b;
		ll hb[b.length()+10];
		hb[0]=0;
		hb[1]=b[0]-'a'+1;
		for(int i=2;i<=b.length();i++){
			hb[i]=(hb[i-1]*26+(b[i-1]-'a'+1))%m;
			//cout<<hb[i]<<endl;
		}
		int x;
		cin>>x;
		for(int y=0;y<x;y++){
			string s;
			cin>>s;
			ll hs=0;
			for(int i=0;i<s.length();i++){
				hs+=(s[i]-96)*p[s.length()-i-1]%m;
				hs%=m;
			}
			int cnt=0;
			//cout<<hs<<endl;
			for(int i=s.length();i<=b.length();i++){
				ll r=hb[i]-p[s.length()]*hb[i-s.length()]%m;
				if(r<0)r+=m;
				//cout<<hb[i]<<" "<<r<<" "<<hb[i-s.length()]<<endl;
				if(r==hs){
					cnt++;
				}
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}


