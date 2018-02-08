#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	auto comp=[](const int &a,const int &b)->bool{
		return a>b;
	};
	priority_queue<int,vector<int>,decltype(comp)> q(comp);
	while(m--)q.push(0);
	int x;
	while(n--){
		cin>>x;
		int t=q.top();
		q.pop();
		q.push(t+x);
	}
	while(!q.empty()){
		x=q.top();
		q.pop();
	}
	cout<<x<<endl;
	return 0;
}

