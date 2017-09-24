#include<iostream>
using namespace std;

int mem[8],r[8];
int main(void){
	ios::sync_with_stdio(false);
	for(int i=0;i<8;i++)
		cin>>mem[i];
	int cmds;
	cin>>cmds;
	for(int i=0;i<cmds;i++){
		string cmd;
		cin>>cmd;
		if(cmd=="LOAD"){
			int rd,ms;
			cin>>rd>>ms;
			r[rd]=mem[ms];
		}
		if(cmd=="STORE"){
			int md,rs;
			cin>>md>>rs;
			mem[md]=r[rs];
		}
		if(cmd=="ADD"){
			int rd,rs1,rs2;
			cin>>rd>>rs1>>rs2;
			r[rd]=r[rs1]+r[rs2];
		}
		if(cmd=="MOVE"){
			int rd,rs;
			cin>>rd>>rs;
			r[rd]=r[rs];
		}
	}
	cout<<r[0]<<endl<<mem[0]<<endl;
	return 0;
}


