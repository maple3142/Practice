#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m){
		int sum=0,x;
		vector<int> v,sel;
		while(n--){
			for(int i=1;i<=m;i++){
				cin>>x;
				v.push_back(x);
			}
			sort(v.begin(),v.end());
			sum+=v.back();
			sel.push_back(v.back());
			v.clear();
		}
		cout<<sum<<endl;
		
		bool flag=true;
		for(int num:sel){
			if(sum%num==0){
				cout<<num<<" ";
				flag=false;
			}
		}
		if(flag)cout<<-1;
		cout<<endl;
		sel.clear();
	}
	return 0;
}

