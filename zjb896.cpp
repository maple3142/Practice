#include<iostream>
#include<algorithm>
#define MAX 750010
using namespace std;
typedef long long int ll;

unsigned int box[MAX],gift[MAX];
int main(void){
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m){
		for(int i=0;i<n;i++){
			cin>>box[i];
		}
		for(int i=0;i<m;i++){
			cin>>gift[i];
		}
		sort(box,box+n);
		sort(gift,gift+m);
		ll bi=0,gi=0,sum=0;
		for(;bi<n&&gi<m;bi++){
			//cout<<box[bi]<<" "<<gift[gi];
			if(box[bi]>=gift[gi]){
				sum+=box[gi];
				gi++;
				//cout<<" "<<sum;
			}
			//cout<<endl;
		}
		if(gi>=m){
			cout<<"YES "<<sum<<endl;
		}
		else{
			cout<<"NO "<<m-gi<<endl;
		}
	}
	return 0;
}


