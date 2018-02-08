#include<iostream>
#include<set>
using namespace std;

int main(void){
	int n;
	cin>>n;
	multiset<int> msp,msn;
	while(n--){
		string s;
		int x;
		cin>>s>>x;
		if(s=="insert"){
			msp.insert(x);
			msn.insert(-1*x);
		}
		else if(s=="delete"){
			msp.erase(msp.find(x));
			msn.erase(msn.find(-1*x));
		}
		else{//query
			if(msp.count(x)!=0){//x exist
				cout<<x<<endl;
				continue;
			}
			multiset<int>::iterator itp=msp.lower_bound(x);
			multiset<int>::iterator itn=msn.lower_bound(-1*x);
			if(abs(*itp-x)==abs(*itn-(-1*x)))//exist 2
				cout<<min(*itp,-1*(*itn))<<" "<<max(*itp,-1*(*itn))<<endl;
			else if(abs(*itp-x)<abs(*itn+x))
				cout<<*itp<<endl;
			else
				cout<<-1*(*itn)<<endl;
		}
	}
	return 0;
}
