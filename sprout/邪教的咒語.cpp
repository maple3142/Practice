#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

struct dot{
	int dp=0;
	int in=1;
	vector<int> tospell,to;
	dot(){
		
	}
};
struct spell{
	int len;
	int last=0;
	map<int,dot> dots;
}ar[100005];
struct asd{
	int s,t;
	asd(int a,int b){
		s=a;
		t=b;
	}
};
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>ar[i].len;
			ar[i].dots[0].in=0;
		}
		for(int i=1;i<=m;i++){
			int s1,t1,s2,t2;
			cin>>s1>>t1>>s2>>t2;
			t2--;
			ar[s1].dots[t1].tospell.push_back(s2);
			ar[s1].dots[t1].to.push_back(t2);
			ar[s2].dots[t2].in++;
		}
		queue<pair<int,pair<int,dot>>> q;
		for(int i=1;i<=n;i++){
			auto endiit=ar[i].dots.end();
			endiit--;
			for(auto iit=ar[i].dots.begin();iit!=endiit;iit++){
				(*iit).second.tospell.push_back(i);
				auto iiit=++iit;
				iit--;
				(*iit).second.to.push_back((*iiit).first);
			}
			for(auto& it:ar[i].dots){
				if(it.second.in==0)q.push(pair<int,pair<int,dot>>(i,it));
			}
		}
		vector<pair<int,pair<int,dot>>> result;
		while(!q.empty()){
			auto pr=q.front();
			result.push_back(pr);
			q.pop();
			cout<<pr.first<<" "<<pr.second.first<<": ";
			for(int i=0;i<pr.second.second.tospell.size();i++){
				cout<<pr.second.second.tospell[i]<<" "<<pr.second.second.to[i]<<";";
				ar[pr.second.second.tospell[i]].dots[pr.second.second.to[i]].in--;
				if(ar[pr.second.second.tospell[i]].dots[pr.second.second.to[i]].in==0)
					q.push(pair<int,pair<int,dot>>(pr.second.second.tospell[i],pair<int,dot>(pr.second.second.to[i],ar[pr.second.second.tospell[i]].dots[pr.second.second.to[i]])));
				
			}
			cout<<endl;
		}
		int mx=0;
		for(auto i:result){
			cout<<i.first<<" "<<i.second.first<<endl;
			for(int j=0;j<i.second.second.tospell.size();j++){
				ar[i.second.second.tospell[j]].dots[i.second.second.to[j]].dp=max(
					ar[i.second.second.tospell[j]].dots[i.second.second.to[j]].dp,
					i.second.second.dp+(i.second.first-ar[i.first].last)
				);
				mx=max(mx,ar[i.second.second.tospell[j]].len-i.second.first+ar[i.second.second.tospell[j]].dots[i.second.second.to[j]].dp);
			}
			ar[i.first].last=i.second.first;
		}
		cout<<mx<<endl;
	}
	return 0;
}

