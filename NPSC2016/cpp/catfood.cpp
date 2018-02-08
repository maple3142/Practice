#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct pt{
    vector<int> target;
    bool watched;
    pt(){
        watched=false;
        target.clear();
    }
    void watch(){
        watched=true;
    }
    void to(int a){
        target.push_back(a);
    }
    bool operator<(pt a){
		return target.size()>a.target.size();
	}
};
pt l[16];
int cats=0;
void DFS(int pos){
    l[pos].watch();
    for(auto i:l[pos].target){
        if(!l[i].watched){
            cout<<"watch "<<i<<" from "<<pos<<endl;
            DFS(i);
        }
        else
            cout<<i<<" in "<<pos<<" has watched!"<<endl;
    }
}
int main(void){
    int n,m;
    while(cin>>n>>m){
        for(int i=1;i<=m;i++){
            int f,t;
            cin>>f>>t;
            l[f].to(t);
        }
        sort(l+1,l+m+1);
        for(int i=1;i<=m;i++){
            if(!l[i].watched){
                cout<<"watch and put cat at "<<i<<endl;
                DFS(i);
                cats++;
            }
        }
        cout<<cats<<endl;
        cats=0;
    }
    return 0;
}
/*
4 4
1 2
3 2
1 3
2 4
*/
