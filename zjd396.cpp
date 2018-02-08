#include<iostream>
using namespace std;

/* generate to[][]
#include<iostream>
#include<vector>
using namespace std;

int primes[11]={2,3,5,7,11,13,17,19,23,29,31}; //max=15+16=31
vector<int> to[17];
int main(void){
	ios::sync_with_stdio(false);
	cout<<"{{},";
	for(int i=1;i<=16;i++){
		for(int j=0;j<11;j++){
			if(primes[j]>i&&primes[j]-i!=i&&primes[j]-i<=16)to[i].push_back(primes[j]-i);
		}
		cout<<'{';
		for(int j=0;j<to[i].size();j++){
			cout<<to[i][j];
			if(j<to[i].size()-1)cout<<',';
		}
		cout<<'}';
		if(i<16)cout<<',';
	}
	cout<<'}';
	return 0;
}
*/

int to[][6]={{},{2,4,6,10,12,16},{1,3,5,9,11,15},{2,4,8,10,14,16},{1,3,7,9,13,15},{2,6,8,12,14},{1,5,7,11,13},{4,6,10,12,16},{3,5,9,11,15},{2,4,8,10,14},{1,3,7,9,13},{2,6,8,12},{1,5,7,11},{4,6,10,16},{3,5,9,15},{2,4,8,14,16},{1,3,7,13,15}};
int ar[17];
bool used[17];
int n;
void dfs(int x=1){
	int now=ar[x];
	if(x==n){
		bool ok=false;
		for(int i=0;i<6;i++){
			if(to[now][i]==ar[1])ok=true;
		}
		if(!ok)return;
		for(int i=1;i<=n;i++){
			cout<<ar[i];
			if(i<n)cout<<' ';
		}
		cout<<endl;
		return;
	}
	for(int i=0;i<6;i++){
		int p=to[now][i];
		if(p==0||p>n||used[p])continue;
		ar[x+1]=p;
		used[p]=true;
		dfs(x+1);
		used[p]=false;
	}
}
int main(void){
	ios::sync_with_stdio(false);
	int kase=1;
	while(cin>>n){
		if(kase>1)cout<<endl;
		cout<<"Case "<<kase++<<':'<<endl;
		if(n==1)cout<<1<<endl;
		else if(n%2==0||n>=16){
			ar[1]=1;
			used[1]=true;
			dfs();
		}
	}
	return 0;
}

