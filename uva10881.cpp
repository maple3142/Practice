#include<iostream>
#include<algorithm>
using namespace std;

struct ant{
	int id;
	int pos;
	int speed;
	ant(){
		
	}
};
struct ID{
	int id;
	int pos;
	ID(){
		
	}
};
ID id[10001];
ant ants[10002];
int main(void){
	ios::sync_with_stdio(false);
	int u;
	cin>>u;
	for(int y=1;y<=u;y++){
		cout<<"Case #"<<y<<":"<<endl;
		int l,t,n;
		cin>>l>>t>>n;
		for(int i=1;i<=n;i++){
			cin>>ants[i].pos;
			id[i].pos=ants[i].pos;
			id[i].id=i;
			ants[i].speed=1;
			char c;
			cin>>c;
			if(c=='L'){
				ants[i].speed=-ants[i].speed;
			}
			ants[i].pos+=ants[i].speed*t;
		}
		sort(id+1,id+n+1,[](ID a,ID b){
			return a.pos<b.pos;
		});
		sort(ants+1,ants+n+1,[](ant a,ant b){
			return a.pos<b.pos;
		});
		for(int i=1;i<=n;i++){
			ants[i].id=id[i].id;
		}
		for(int i=1;i<=n;i++){
			if(ants[i].pos<0 || ants[i].pos>l){
				
			}
			else{
				if(ants[i+1].pos==ants[i].pos){
					ants[i].speed=ants[i+1].speed=0;
				}
			}
		}
		sort(ants+1,ants+n+1,[](ant a,ant b){
			return a.id<b.id;
		});
		for(int i=1;i<=n;i++){
			if(ants[i].speed==0){
				cout<<ants[i].pos<<" Turning"<<endl;
			}
			else if(ants[i].pos<0 || ants[i].pos>l){
				cout<<"Fell off"<<endl;
			}
			else{
				if(ants[i].speed==1){
					cout<<ants[i].pos<<" R"<<endl;
				}
				else{
					cout<<ants[i].pos<<" L"<<endl;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}

