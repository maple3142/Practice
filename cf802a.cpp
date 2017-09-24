#include<iostream>
using namespace std;

int ar[3000];
int cnt[85];
bool has[85];
int main(void){
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>ar[i];
		cnt[ar[i]]++;
	}
	int chf=0,c=0;
	for(int i=0;i<n;i++){
		if(!has[ar[i]]){
			if(c<k){
				c++;
				chf++;
				has[ar[i]]=true;
			}
			else{
				int mn=0x3f3f3f3f,mni=0;
				for(int j=0;j<n;j++){
					if(mn>cnt[ar[j]]&&has[ar[j]]){
						mn=cnt[ar[j]];
						mni=ar[j];
					}
				}
				has[mni]=false;
				chf++;
				has[ar[i]]=true;
			}
		}
		cnt[ar[i]]--; 
	}
	cout<<chf<<endl;
	return 0;
}

