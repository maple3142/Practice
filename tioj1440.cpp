#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct food{
	int value;
	int money;
	food(){
	}
	food(int a,int b){
		value=a;
		money=b;
	}
};
vector<food> v;
int req[1000005];
bool comp(food a,food b){
	return a.value<b.value;
}
int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>req[i];
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int b,c;
		cin>>b>>c;
		v.push_back(food(b,c));
	}
	sort(v.begin(),v.end(),comp);
	sort(req,req+n);
	int reqi=0;
	long long int money=0;
	for(int i=0;i<m;i++){
		if(v[i].value>=req[reqi]){
			money+=v[i].money;
			reqi++;
			if(reqi>=n)break;
		}
	}
	if(reqi<n){
		cout<<"Impossible."<<endl;
	}
	else{
		cout<<money<<endl;
	}
	return 0;
}


