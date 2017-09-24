#include<iostream>
#include<queue>
using namespace std;

int main(void){
	long long int a,b,c,d;
	while(cin>>a>>b>>c>>d){
		priority_queue<long long int> q;
		q.push(a);
		q.push(b);
		q.push(c);
		q.push(d);
		cout<<q.top()<<endl;
	}
	return 0;
}


