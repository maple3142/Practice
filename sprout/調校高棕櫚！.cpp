#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int ll;

int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	while(n--){
		ll a;
		cin>>a;
		if(a==1)cout<<1;
		else{
			vector<int> v;
			for(int i=9;i>=2;i--){
				while(a%i==0){
					v.push_back(i);
					a/=i;
				}
			}
			if(a<10){
				if(a>1)v.push_back(a);
				sort(v.begin(),v.end());
				for(auto i:v){
					cout<<i;
				}
			}
			else cout<<-1;
		}
		cout<<endl;
	}
	return 0;
}
