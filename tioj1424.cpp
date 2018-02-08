#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int ar[1000];
int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		priority_queue<int> pq; 
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			pq.push(-x);
		}
		int sum=0;
		while(pq.size()>1){
			int a=-pq.top();
			pq.pop();
			int b=-pq.top();
			pq.pop();
			sum+=a+b;
			pq.push(-a-b);
		}
		cout<<sum<<endl;
	}
	return 0;
}

