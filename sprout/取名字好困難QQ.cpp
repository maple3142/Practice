#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		vector<int> ar;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			if(2*x>=m)ar.push_back(2*x);
			if(x>=m)ar.push_back(x);
		}
		if(ar.size()==0){
			cout<<0<<endl;
		}
		else{
			vector<int> t;
			t.push_back(ar[0]); 
			for(int i=1;i<ar.size();i++){
				if(ar[i]>=t.back()){
					t.push_back(ar[i]);
				}
				else{
					auto it=lower_bound(t.begin(),t.end(),ar[i]);
					int cnt=0;
					for(auto ii=it;;ii++){
						if(cnt>1 || *ii!=*it)break;
						else cnt++;
					}
					if(cnt==1)*it=ar[i];
				}
			}
			for(auto u:t){
				cout<<u<<" ";
			}
			cout<<endl;
			cout<<t.size()<<endl;
		}
	}
	return 0;
}
