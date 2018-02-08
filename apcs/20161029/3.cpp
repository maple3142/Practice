#include<iostream>
#include<set>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int n,m,k;
	set<int> s;
	while(cin>>n>>m>>k){
		for(int i=1;i<=n;i++){
			s.insert(i);
		}
		k++;
		int cur=0;
		while(k--){
			int cnt=0;
			while(cnt<m){
				cur++;
				if(cur>n)cur-=n;
				if(s.find(cur)!=s.end())cnt++;
			}
			s.erase(cur);
		}
		cout<<cur<<endl;
	} 
	return 0;
}

