#include<iostream>
#include<deque>
using namespace std;

struct p{
	int a,b;
	p(int t,int y){
		a=t;
		b=y;
	}
};
deque<p> d;
int ans[1000010];
int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		for(int u=d.size()-1;u>=0;u--){
			if(d[u].b>x){
				break;
			}
			ans[d[u].a]=i-d[u].a;
			d.pop_back();
		}
		d.push_back(p(i,x));
	}
	for(int u=d.size()-1;u>=0;u--){
		ans[d[u].a]=n-1-d[u].a;
		d.pop_back();
	}
	for(int i=0;i<n;i++)
		cout<<ans[i]<<endl;
	return 0;
}


