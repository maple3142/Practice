#include<iostream>
#include<sstream>
using namespace std;
typedef long long int ll;

ll dp[301][301];
int main(void){
	dp[0][0]=1;
	for(int i=1;i<=300;i++){
		for(int j=0;j+i<=300;j++){
			for(int k=1;k<=300;k++){
				dp[i+j][k]+=dp[j][k-1];
			}
		}
	}
	ios::sync_with_stdio(false);
	string s;
	while(getline(cin,s)){
		stringstream ss(s);
		int tmp[3],i=0;
		while(!ss.eof()){
			ss>>tmp[i++];
		}
		ss.clear();
		if(i==1){
			ll sum=0;
			for(int i=0;i<=tmp[0];i++){
				sum+=dp[tmp[0]][i];
			}
			cout<<sum<<endl;
		}
		if(i==2){
			ll sum=0;
			if(tmp[1]>300)tmp[1]=300;
			for(int i=0;i<=tmp[1];i++){
				sum+=dp[tmp[0]][i];
			}
			cout<<sum<<endl;
		}
		if(i==3){
			ll sum=0;
			if(tmp[1]>300)tmp[1]=300;
			if(tmp[2]>300)tmp[2]=300;
			for(int i=tmp[1];i<=tmp[2];i++){
				sum+=dp[tmp[0]][i];
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}

