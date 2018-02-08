#include<iostream>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		int seq[n+1];
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			seq[x]=i;
		}
		int lpos,rpos,dest;
		cin>>lpos>>dest;
		rpos=lpos;
		long long int time=0;
		while(lpos!=dest){
			time+=(seq[lpos-1]-time%n+n)%n;
			lpos=(lpos!=1?lpos-1:n);
			//cout<<time<<" "<<lpos<<endl; 
		}
		//cout<<"r"<<endl;
		long long int rtime=0;
		while(rpos!=dest){
			rtime+=(seq[rpos]-rtime%n+n)%n;
			rpos=(rpos!=n?rpos+1:1);
			//cout<<rtime<<" "<<rpos<<endl; 
		}
		cout<<min(time,rtime)+1<<endl;
	}
	return 0;
}


