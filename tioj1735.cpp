#include<iostream>
#include<queue>
#include<cmath> 
using namespace std;
typedef long long int ll;

int to(char c){
	return c-'a'+1;
}
ll hsh(string s){
	ll sum=0;
	for(int i=0;i<s.length();i++){
		sum*=27;
		sum+=to(s[i]);
	}
	return sum;
}
int main(void){
	ios::sync_with_stdio(false);
	int k;
	string s;
	while(cin>>k>>s){
		if(s.length()<2*k){
			cout<<0<<endl;
			continue;
		}
		int X=pow(27,k-1);
		queue<ll> q;
		q.push(hsh(s.substr(0,k)));
		int cnt=0;
		for(int i=k;i<s.length();i++){
			ll h=q.back();
			h=(h-to(s[i-k])*X)*27+to(s[i]);
			q.push(h);
			if(q.size()>k+1){
				q.pop();
			}
			if(q.size()==k+1&&q.front()==q.back()){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

