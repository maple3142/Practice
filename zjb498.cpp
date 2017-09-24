#include<iostream>
#include<map>
using namespace std;

int find(string s,string f){
	int count=0;
    int nPos=s.find(f,0);
    while(nPos!=string::npos){
        count++;
        nPos=s.find(f,nPos+1);
    }
    return count;
}
int main(void){
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int cse=1;
	int n;
	while(cin>>n){
		cout<<"Case #"<<cse<<":"<<endl;
		cse++;
		string dict[n];
		map<string,bool> m;
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			if(!m[s]){
				dict[i]=s;
			}
			m[s]=true;
		}
			
		int q;
		cin>>q;
		for(int i=0;i<q;i++){
			string s;
			cin>>s;
			int count=0;
			for(int j=0;j<n;j++){
				if(dict[j]!="")
					count+=find(s,dict[j]);
			}
			cout<<count<<endl;
		}
	}
	return 0;
}


