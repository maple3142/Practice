#include<iostream>
#include<deque>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		deque<int> dq;
		int p,q;
		cin>>p>>q;
		while(p>=2&&q>=1){
			p-=2;
			q--;
			dq.push_front(1);
			dq.push_front(0);
			dq.push_front(1);
		}
		if(p&&q){
			dq.push_front(1);
			dq.push_front(0);
			q--;
			p--;
		}
		while(q--)dq.push_front(0);
		while(p--)dq.push_back(1);
		long long int n=0;
		while(!dq.empty()){
			n=n<<1;
			n+=dq.front();
			dq.pop_front();
		}
		cout<<n<<endl;
	}
	return 0;
}

