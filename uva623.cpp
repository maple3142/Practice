#include<iostream>
using namespace std;

string ar[1001];
string c(int a,string b){
	char tmp[b.length()+1];
	tmp[b.length()]='0';
	for(int i=b.length()-1;i>=0;i--){
		int t=a*(b[i]-'0');
		t+=(int)(tmp[i+1]-'0');
		if(t<10){
			tmp[i+1]='0'+t;
			tmp[i]='0';	
		}
		else{
			tmp[i+1]='0'+t%10;
			tmp[i]='0'+t/10;
		}
	}
	return string(tmp);
}
string chen(string a,string b){
	cout<<a<<"*"<<b<<endl; 
	string S[b.length()];
	for(int i=0;i<b.length();i++){
		S[i]=c(b[i]-'0',a);
		for(int j=0;j<i;j++){
			S[i]+='0';
		}
		cout<<S[i]<<endl;
	}
	char tmp[b.length()+1];
	for(int i=b.length()-1;i>=0;i--){
		int t=0;
		for(int j=0;j<b.length();j++){
			cout<<S[j][i]<<"+";
			t+=S[j][i]-'0';
		}
		cout<<"="<<t<<endl;
		t+=(int)(tmp[i+1]-'0');
		int k=0;
		while(t>10){
			tmp[i-k]='0'+t%10;
			k++;
			t/=10;
			t+=(int)(tmp[i-k]-'0');
		}
		tmp[i-k]='0'+t%10;
	}
	return string(tmp);
}
int main(void){
	ios::sync_with_stdio(false);
	ar[0]=ar[1]="1";
	for(int i=1;i<=2;i++){
		ar[i]=chen(ar[i-1],to_string(i));
	}
	int n;
	while(cin>>n){
		cout<<n<<"!"<<endl;
		cout<<ar[n]<<endl;
	}
	return 0;
}

