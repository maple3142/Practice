#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

int ar1[62505],ar2[62505];
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	int cse=1;
	while(T--){
		int n,p,q;
		cin>>n>>p>>q;
		unordered_map<int,int> m;
		for(int i=1;i<=p+1;i++){
			int x;
			cin>>x;
			ar1[i]=i;
			m[x]=i;
		}
		int j=1;
		for(int i=1;i<=q+1;i++){
			int x;
			cin>>x;
			if(m[x]!=0){
				ar2[j++]=m[x];
			}
		}
		vector<int> lis;
		lis.push_back(0);
		for(int i=1;i<j;i++){
			if(lis.back()<ar2[i]){
				lis.push_back(ar2[i]);
			}
			else{
				*lower_bound(lis.begin(),lis.end(),ar2[i])=ar2[i];
			}
		}
		cout<<"Case "<<cse++<<": "<<lis.size()-1<<endl;
	}
	return 0;
}


