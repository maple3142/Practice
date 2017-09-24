#include<iostream>
#include<sstream>
#include<cmath>
#include<unordered_map>
#include<functional>
using namespace std;

struct ddouble{
	double num;
	ddouble(double x){
		num=x;
	}
	bool operator==(const ddouble& a)const{
		return num-a.num<0.001;
	}
	bool operator<(const ddouble& a)const{
		return num<a.num;
	}
};
namespace std{
	template<>
	struct hash<ddouble>{
		int operator()(const ddouble& a)const{
			return hash<double>()(a.num);
		}
	};
}
unordered_map<int,int> M;
int X[750],Y[750];
int main(void){
	ios::sync_with_stdio(false);
	for(int i=1;i<=700;i++){
		M[i*i-i]=i;
	}
	int T;
	string s;
	cin>>T;
	getline(cin,s);
	getline(cin,s);
	while(T--){
		int k=0;
		while(getline(cin,s)){
			if(s.empty())break;
			stringstream ss(s);
			ss>>X[k]>>Y[k];
			k++;
		}
		int mx=0;
		unordered_map<ddouble,unordered_map<ddouble,int>> m;
		for(int i=0;i<k;i++){
			for(int j=i+1;j<k;j++){
				int dx=abs(X[i]-X[j]);
				int dy=abs(Y[i]-Y[j]);
				double t;
				if(dy==0){
					t=0x3f3f3f3f;
				}
				else{
					t=(double)dx*1000000/dy;
				}
				double u=Y[i]-t*X[i];
				ddouble tt(t),uu(u);
				m[tt][uu]++;
				mx=max(mx,m[tt][uu]);
			}
		}
		cout<<mx<<" "<<M[2*mx]<<endl<<endl;
	}
	return 0;
}

