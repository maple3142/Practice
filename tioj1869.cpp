#include<iostream>
using namespace std;

int n;
int bit[1100][1100];
void upd(int x,int y,int v){
	x++;
	y++;
	for(int i=x;i<=n;i+=i&(-i))
		for(int j=y;j<=n;j+=j&(-j))
			bit[i][j]+=v;
}
int q(int px,int py){
	px++;
	py++;
	int sum=0;
	for(int i=px;i>0;i-=i&(-i))
		for(int j=py;j>0;j-=j&(-j))
			sum+=bit[i][j];
	return sum;
}
int main(void){
	ios::sync_with_stdio(false);
	cin>>n;
	int act;
	while(cin>>act){
		if(act==1){
			int x,y,z;
			cin>>x>>y>>z;
			upd(x,y,z);
		}
		else{
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			cout<<q(x2,y2)-q(x1-1,y2)-q(x2,y1-1)+q(x1-1,y1-1)<<endl;
		}
	}
	return 0;
}

