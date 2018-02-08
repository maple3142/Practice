#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int n,m;
stack<int> s;
bool vis[9000][9000];
int X[9]={0,-2,-1,1,2,2,1,-1,-2};
int Y[9]={0,1,2,2,1,-1,-2,-2,-1};
bool ok=false;
void walk(int x,int y){
    //cout<<x<<","<<y<<endl;
    if(x==n-1 && y==m-1){
        ok=true;
    }
    for(int i=1;i<=8 && !ok;i++){
        if(!vis[x+X[i]][y+Y[i]] && x+X[i]>=0 && x+X[i]<n && y+Y[i]>=0 && y+Y[i]<m){
            vis[x+X[i]][y+Y[i]]=true;
            //cout<<x<<","<<y<<" ---"<<i<<"---> ";
            walk(x+X[i],y+Y[i]);
            if(ok){
                s.push(i);
                vis[x+X[i]][y+Y[i]]=false;
            }
        }
    }
}
void go(){
    cout<<"YES"<<endl;
    vis[0][0]=true;
    walk(0,0);
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
    memset(vis,0,sizeof(vis));
    ok=false;
}
int main(void){
    while(cin>>n>>m){
        if(n==1 || m==1)
            cout<<"NO"<<endl;
        else if(n==2 || m==2){
            if(n==2){
                if((m-3)%4==0)go();
                else cout<<"NO"<<endl;
            }
            else if(m==2){
                if((n-3)%4==0)go();
                else cout<<"NO"<<endl;
            }
        }
        else go();
    }
    return 0;
}
