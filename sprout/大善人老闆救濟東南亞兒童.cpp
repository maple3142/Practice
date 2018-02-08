#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		queue<int> q;
		int t=n;
		while(t--){
			int x;
			cin>>x;
			q.push(x);
		}
		stack<int> s;
		int i=1;
		while(i<=n+1&&!q.empty()){
			if(s.empty())s.push(i++);
			if(s.top()==q.front()){
				s.pop();
				q.pop();
			}
			else{
				s.push(i++);
			}
		}
		cout<<(q.empty()?"Yes":"No")<<endl;
		while(!s.empty()){
			s.pop();
		}
		while(!q.empty()){
			q.pop();
		}
	}
	return 0;
}

