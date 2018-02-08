#include<iostream>
using namespace std;
typedef unsigned long long int ll;

const int win=48763;
const int lose=48764;
const int ssame=48765;
int minx(int a,int b,int y){
	int rtn=a;
	if(a>b){
		int x=b;
		while(x%a!=0){
			if(x>y)return y;
			x+=b;
		}
		rtn=x;
	}
	else if(a<b){
		int x=a;
		while(x%b!=0){
			if(x>y)return y;
			x+=a;
		}
		rtn=x;
	}
	return rtn;
}
int compare(char a,char b){
	switch(a){
		case 'R':
			switch(b){
				case 'R':
					return ssame;
				case 'S':
					return win;
				case 'P':
					return lose;
			}
		case 'S':
			switch(b){
				case 'S':
					return ssame;
				case 'P':
					return win;
				case 'R':
					return lose;
			}
		case 'P':
			switch(b){
				case 'P':
					return ssame;
				case 'R':
					return win;
				case 'S':
					return lose;
			}
	}
}
int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	string upseq,downseq;
	cin>>upseq>>downseq;
	ll up=0,down=0,same=0;
	ll d=minx(upseq.length(),downseq.length(),n);
	for(int i=0;i<d;i++){
		int result=compare(upseq[ i%upseq.length() ],downseq[ i%downseq.length() ]);
		switch(result){
			case win:
				up++;
				break;
			case lose:
				down++;
				break;
			case ssame:
				same++;
				break;
		}
	}
	int w=n/d;
	up*=w;
	down*=w;
	same*=w;
	for(int i=0;i<n-w*d;i++){
		int result=compare(upseq[ i%upseq.length() ],downseq[ i%downseq.length() ]);
		switch(result){
			case win:
				up++;
				break;
			case lose:
				down++;
				break;
			case ssame:
				same++;
				break;
		}
	}
	cout<<up<<" "<<down<<" "<<same<<endl;
	return 0;
}

