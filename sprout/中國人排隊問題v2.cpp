#include<iostream>
#include<cstring>
using namespace std;

const int MAX=1000000;
int mangrp[MAX];
int back[MAX];
int grplast[1001];
int main(void){
	ios::sync_with_stdio(false);
	int line=1;
	int n;
	while(cin>>n){
		if(n==0)break;
		cout<<"Scenario #"<<line++<<endl;
		for(int i=1;i<=n;i++){
			int c;
			cin>>c;
			for(int j=1;j<=c;j++){
				int x;
				cin>>x;
				mangrp[x]=i;
			}
		}
		int st=-1,ed=-1,size=0,mxid=0;
		string s;
		while(cin>>s){
			if(s=="STOP")break;
			if(s=="ENQUEUE"){
				int x;
				cin>>x;
				mxid=max(x,mxid);
				if(size==0){
					//cout<<"0->1"<<endl;
					st=ed=x;
					if(mangrp[x]!=0){
						grplast[mangrp[x]]=x;
					}
					back[x]=x;
				}
				else{
					if(mangrp[x]==0||grplast[mangrp[x]]==0){
						//cout<<x<<" join at last"<<endl;
						back[ed]=back[x]=x;
						ed=x;
						if(grplast[mangrp[x]]==0){
							grplast[mangrp[x]]=x;
						}
					}
					else{
						//cout<<x<<" joined after "<<grplast[mangrp[x]]<<endl;
						if(ed!=grplast[mangrp[x]]){
							back[x]=back[grplast[mangrp[x]]];
							back[grplast[mangrp[x]]]=x;
						}
						else
							ed=back[x]=back[grplast[mangrp[x]]]=x;
						if(mangrp[x]!=0)
							grplast[mangrp[x]]=x;
					}
					/*if(mangrp[x]!=0)
						cout<<x<<" is group #"<<mangrp[x]<<" last"<<endl;
					else
						cout<<x<<" no group"<<endl;*/
				}
				size++;
			}
			if(s=="DEQUEUE"){
				cout<<st<<endl;
				size--;
				if(size<=0){
					back[st]=0;
					grplast[mangrp[st]]=0;
					st=ed=-1;
					size=0;
				}
				else{
					if(grplast[mangrp[st]]==st&&mangrp[st]!=0){
						//cout<<"group #"<<mangrp[st]<<" all leaved"<<endl;
						grplast[mangrp[st]]=0;
					}
					int backst=back[st];
					back[st]=0;
					st=backst;
				}
			}
			//cout<<"size: "<<size<<endl;
			/*cout<<st<<" "<<ed<<endl;
			for(int i=1;i<=10;i++){
				cout<<back[i]<<" ";
			}
			cout<<endl;*/
		}
		memset(mangrp,0,4*n);
		memset(grplast,0,4*n);
		memset(back,0,mxid*4);
		cout<<endl;
	}
	return 0;
}

