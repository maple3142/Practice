#include<iostream>
#include<functional>
#include<set>
#include<algorithm>
using namespace std;

struct point{
	int pos,h,t;
	bool operator<(const point &a)const{
		if(pos!=a.pos)
			return pos<a.pos;
		else if(h!=a.h)
			return h<a.h;
		else
			return t<a.t;
	}
};
multiset<int,greater<int>> s;
vector<point> v;
int main(void){
	int n;
	while(cin>>n){
		if(!n)break;
		for(int i=0;i<n;i++){
			int l,h,r;
			cin>>l>>h>>r;
			v.push_back((point){l,h,1});
			v.push_back((point){r,h,2});
		}
		sort(v.begin(),v.end());
		int now=0;
		s.insert(0);
		for(int i=0;i<v.size();){
			int j=i;
			while(j<v.size()&&v[j].pos==v[i].pos){
				if(v[j].t==1)
					s.insert(v[j].h);
				else
					s.erase(s.find(v[j].h));
				j++;
			}
			if(*s.begin()!=now){
				now=*s.begin();
				cout<<v[i].pos<<" "<<now<<" ";
			}
			i=j;
		}
		cout<<endl;
		s.clear();
		v.clear();
	}
}
