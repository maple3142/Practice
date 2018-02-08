#include<iostream>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int a,b,c,d,e,f;
	while(cin>>a>>b>>c>>d>>e>>f){
		if(a==b&&b==c&&c==d&&d==e&&e==f&&f==0)break;
		int cnt=d+e+f;
		a-=11*e;
		b-=5*d;
		cnt+=(c/4);
		if(c%4){
			cnt++;
			switch(c%4){
				case 1:
					b-=5;
					a-=7;
					break;
				case 2:
					b-=3;
					a-=6;
					break;
				case 3:
					b-=1;
					a-=5;
					break;
			}
		}
		if(b>0){
			cnt+=b/9;
			if(b%9)cnt++;
			a-=(36-(b%9)*4);
		}
		else if(b<0)
			a-=(-b)*4;
		if(a>0){
			 cnt+=(a/36);
			 if(a%36)cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}

