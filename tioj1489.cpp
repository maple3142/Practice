#include<iostream>
#include<queue>
using namespace std;

int cnt[30];
int main(void){
	ios::sync_with_stdio(false);
	int n;
	string s;
	while(cin>>n){
		if(n==0)break;
		cin>>s;
		
		int ccnt=0,l,r=s.length()-1;
		queue<int> q;
		for(int i=0;i<s.length();i++){
			char c=s[i];
			q.push(i);
			if(cnt[c-'a']==0)ccnt++;
			cnt[c-'a']++;
			
			if(ccnt==26){
				while(cnt[s[q.front()]-'a']>1){
					cnt[s[q.front()]-'a']--, q.pop();
				}
				if(i-q.front()>r-l){
					l=q.front();
					r=i;
				}
			}
		}
		if(ccnt==26){
			for(int i=l;i<=r;i++)cout<<s[i];
		}
		else cout<<"not found";
		cout<<endl;
	}
	return 0;
}

