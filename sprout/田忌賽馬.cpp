#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int T,n,k;
const int INF=100000001;
struct horse{
	int speed;
	int rate;
	horse(){
		
	}
};
horse my[10005];
horse king[10005];
bool win(int day){
	int myspeed[10005];
	for(int i=0;i<n;i++){
		myspeed[i]=my[i].speed+my[i].rate*day;
	}
	sort(myspeed,myspeed+n,[](int a,int b){
		return a>b;
	});
	int wincnt=0;
	for(int i=0;i<n;i++){
		if(myspeed[i]>king[i].speed){
			wincnt++;
		}
	}
	return wincnt>=k;
}
int find(int l,int r){
	if(l==r)return l;
	int mid=(l+r)/2;
	if(win(mid)){
		return find(l,mid);
	}
	else{
		return find(mid+1,r);
	}
}
int main(void){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>my[i].speed>>my[i].rate;
		}
		for(int i=0;i<n;i++){
			cin>>king[i].speed;
		}
		sort(king,king+n,[](horse a,horse b){
			return a.speed>b.speed;
		});
		int m=find(0,INF);
		if(m<INF){
			cout<<m;
		}
		else{
			cout<<-1;
		}
		cout<<endl;
	}
	return 0;
}

