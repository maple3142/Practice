#include<iostream>
#include<queue>
using namespace std;

int main(void){
	int n;
	while(cin>>n){
		priority_queue<int> q;
		int count=0;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			q.push(x*-1);
			count++;
		}
		long long int sum=0;
		for(int i=count-1;i>=0;i--){
			sum+=q.top()*-1*i;
			q.pop();
		}
		cout<<sum*100<<endl;
	}
	return 0;
}


