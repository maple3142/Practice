#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<int,int> m;
int ar[3][3]={{1,2,3},{4,5,6},{7,8,0}};
int hsh(int ar[3][3]){
	int s=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			s=(s+ar[i][j])*10;
		}
	}
	return s;
}
void dfs(int ar[3][3],int step=1){
	if(step>20)return;
	if(m[hsh(ar)] && m[hsh(ar)]<=step)return;
	step++;
	m[hsh(ar)]=step;
	/*for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<ar[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(ar[i][j]==0){
				if(i>0){
					swap(ar[i-1][j],ar[i][j]);
					dfs(ar,step);
					swap(ar[i-1][j],ar[i][j]);
				}
				if(i<2){
					swap(ar[i+1][j],ar[i][j]);
					dfs(ar,step);
					swap(ar[i+1][j],ar[i][j]);
				}
				if(j>0){
					swap(ar[i][j-1],ar[i][j]);
					dfs(ar,step);
					swap(ar[i][j-1],ar[i][j]);
				}
				if(j<2){
					swap(ar[i][j+1],ar[i][j]);
					dfs(ar,step);
					swap(ar[i][j+1],ar[i][j]);
				}
			}
		}
	}
}
int main(void){
	ios::sync_with_stdio(false);
	dfs(ar);
	int T;
	cin>>T;
	while(T--){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				cin>>ar[i][j];
			}
		}
		if(m[hsh(ar)]){
			cout<<"Easy"<<endl;
		}
		else{
			cout<<"Hard"<<endl;
		}
	}
	return 0;
}

