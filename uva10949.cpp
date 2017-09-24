#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int a[20001],b[20001];
int aa[1000],bb[1000];
int ar[25][25];
int main(void){
	ios::sync_with_stdio(false);
	int T,cse=1;
	cin>>T;
	while(T--){
		int h,w;
		cin>>h>>w;
		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++){
				char c;
				cin>>c;
				ar[i][j]=c-33;
			}
		int n,nx,ny;
		cin>>n>>ny>>nx;
		string N;
		cin>>N;
		int m,mx,my;
		cin>>m>>my>>mx;
		string M;
		cin>>M;
		a[0]=ar[ny][nx];
		for(int i=0;i<n;i++){
			char c=N[i];
			if(c=='N')ny--;
			if(c=='S')ny++;
			if(c=='E')nx++;
			if(c=='W')nx--;
			a[++i]=ar[ny][nx];
		}
		b[0]=ar[my][mx];
		for(int i=0;i<m;i++){
			char c=M[i];
			if(c=='N')my--;
			if(c=='S')my++;
			if(c=='E')mx++;
			if(c=='W')mx--;
			b[++i]=ar[my][mx];
		}
		
		for(int i=0;i<n;i++)
			bb[a[i]]=i;
		for(int i=0;i<m;i++)
			aa[i]=bb[b[i]];
		vector<int> aaa;
		aaa.push_back(aa[0]);
		for(int i=1;i<n;i++){
			if(aa[i]>aaa.back()){
				aaa.push_back(aa[i]);
			}
			else{
				*lower_bound(aaa.begin(),aaa.end(),aa[i])=aa[i];
			}
		}
		cout<<"Case "<<cse++<<": "<<n+1-aaa.size()<<" "<<m+1-aaa.size()<<endl;
	}
	return 0;
}

