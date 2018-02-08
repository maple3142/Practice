#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<stack>
#include<iomanip>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long int ll;

int minx(int a,int b){
	int rtn=a;
	if(a>b){
		int x=b;
		while(x%a!=0){
			x+=b;
		}
		rtn=x;
	}
	else if(a<b){
		int x=a;
		while(x%b!=0){
			x+=a;
		}
		rtn=x;
	}
	return rtn;
}
string compare(char a,char b){
	switch(a){
		case 'R':
			switch(b){
				case 'R':
					return "same";
				case 'S':
					return "win";
				case 'P':
					return "lose";
			}
		case 'S':
			switch(b){
				case 'S':
					return "same";
				case 'P':
					return "win";
				case 'R':
					return "lose";
			}
		case 'P':
			switch(b){
				case 'P':
					return "same";
				case 'R':
					return "win";
				case 'S':
					return "lose";
			}
	}
}
int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	string upseq,downseq;
	cin>>upseq>>downseq;
	if(upseq.length()>n && downseq.length()>n){
		int up=0,down=0,same=0;
		for(int i=0;i<n;i++){
			string result=compare(upseq[i],downseq[i]);
			if(result=="win")
				up++;
			if(result=="lose")
				down++;
			if(result=="same")
				same++;
		}
		cout<<up<<" "<<down<<" "<<same<<endl;
	}
	else if(upseq.length()>n && downseq.length()<=n){
		int up=0,down=0,same=0;
		while(downseq.length()<n){
			downseq+=downseq;
		}
		for(int i=0;i<n;i++){
			string result=compare(upseq[i],downseq[i]);
			if(result=="win")
				up++;
			if(result=="lose")
				down++;
			if(result=="same")
				same++;
		}
		cout<<up<<" "<<down<<" "<<same<<endl;
	}
	else if(upseq.length()<=n && downseq.length()>n){
		int up=0,down=0,same=0;
		while(upseq.length()<n){
			upseq+=upseq;
		}
		for(int i=0;i<n;i++){
			string result=compare(upseq[i],downseq[i]);
			if(result=="win")
				up++;
			if(result=="lose")
				down++;
			if(result=="same")
				same++;
		}
		cout<<up<<" "<<down<<" "<<same<<endl;
	}
	else{
		int d=minx(upseq.length(),downseq.length());
		while(upseq.length()<d){
			upseq+=upseq;
		}
		while(downseq.length()<d){
			downseq+=downseq;
		}
		vector<string> result;
		int up=0,down=0,same=0;
		for(int i=0;i<d;i++){
			result.push_back(compare(upseq[i],downseq[i]));
			if(result[i]=="win")
				up++;
			if(result[i]=="lose")
				down++;
			if(result[i]=="same")
				same++;
		}
		int w=n/d;
		up*=w;
		down*=w;
		same*=w;
		for(int i=0;i<n-d*w;i++){
			if(result[i]=="win")
				up++;
			if(result[i]=="lose")
				down++;
			if(result[i]=="same")
				same++;
		}
		cout<<up<<" "<<down<<" "<<same<<endl;
	}
	
	return 0;
}

