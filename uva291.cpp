#include<iostream>
#include<vector>
using namespace std;
/*
struct edge{
	int l,r;
	bool vis=false;
	edge(){
		
	}
	edge(int a,int b){
		l=a;
		r=b;
	}
}E[8];
void dfs(int now,vector<int> x){
	bool flag=false;
	for(int i=0;i<8;i++)
		if(!E[i].vis&&(E[i].l==now||E[i].r==now)){
			flag=true;
			int to;
			if(E[i].l==now)to=E[i].r;
			else to=E[i].l;
			vector<int> xx(x);
			xx.push_back(to);
			E[i].vis=true;
			dfs(to,xx);
			E[i].vis=false;
		}
	if(!flag&&x.size()==9){
		for(int c:x){
			cout<<c;
		}
		cout<<endl;
	}
	 
}
int main(void){
	ios::sync_with_stdio(false);
	E[0]=edge(1,2);
	E[1]=edge(1,3);
	E[2]=edge(1,5);
	E[3]=edge(2,3);
	E[4]=edge(2,5);
	E[5]=edge(3,4);
	E[6]=edge(3,5);
	E[7]=edge(4,5);
	dfs(1,vector<int>({1}));
	return 0;
}
*/

int main(void){
	puts("123153452\n123154352\n123451352\n123453152\n123513452\n123543152\n125134532\n125135432\n125315432\n125345132\n125431532\n125435132\n132153452\n132154352\n132534512\n132543512\n134512352\n134512532\n134521532\n134523512\n134532152\n134532512\n135123452\n135125432\n135215432\n135234512\n135432152\n135432512\n152134532\n152135432\n152345312\n152354312\n153123452\n153125432\n153213452\n153254312\n153452132\n153452312\n154312352\n154312532\n154321352\n154325312\n154352132\n154352312");
}
