#include<iostream>
#include<vector>
using namespace std;

struct obj{
	int x,y;
	obj(){
		
	}
	obj(int a,int b){
		x=a;
		y=b;
	}
};
int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int x,y;
	cin>>x>>y;
	vector<obj> v;
	int z;
	cin>>z;
	for(int i=0;i<z;i++){
		int t,u;
		cin>>t>>u;
		v.push_back(obj(t,u));
	}
	int q;
	cin>>q;
	for(int u=0;u<q;u++){
		int a,b,i,v1=n,v2=0,v3=n,v4=0;
		cin>>a>>b;
		switch(a){
			case 1:
				for(i=0;i<v.size();i++){
					if(v[i].x>x&&v[i].x<x+b&&v[i].y==y){
						v1=min(v[i].x,v1);
					}
				}
				if(v1==n&&x+b>n)x=n;
				else if(v1==n)x+=b;
				else x=v1-1;
				break;
			case 2:
				for(i=0;i<v.size();i++){
					if(v[i].x<x&&v[i].x>x-b&&v[i].y==y){
						v2=max(v[i].x,v2);
						break;
					}
				}
				if(v2==0&&x-b<1)x=1;
				else if(v2==0)x-=b;
				else x=v2+1;
				break;
			case 3:
				for(i=0;i<v.size();i++){
					if(v[i].y>y&&v[i].y<y+b&&v[i].x==x){
						v3=min(v[i].y,v3);
						break;
					}
				}
				if(v3==n&&y+b>n)y=n;
				else if(v3==n)y+=b;
				else y=v3-1;
				break;
			case 4:
				for(i=0;i<v.size();i++){
					if(v[i].y<y&&v[i].y>y-b&&v[i].x==x){
						v4=max(v[i].y,v4);
						break;
					}
				}
				if(v4==0&&y-b<1)y=1;
				else if(v4==0)y-=b;
				else y=v4+1;
				break;
		}
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}


