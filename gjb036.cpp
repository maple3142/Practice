#include<iostream>
#include<queue>
using namespace std;

int main(void){
	int n;
	while(cin>>n){
		priority_queue<int> q;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			q.push(x*-1);
		}
		int sum=0;
		while(!(q.size()==1)){
			int a=q.top()*-1;
			q.pop();
			int b=q.top()*-1;
			q.pop();
			int x=a+b;
			sum+=x;
			q.push(x*-1);
		}
		cout<<sum<<endl;
	}
	return 0;
}


