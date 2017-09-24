#include<iostream>
using namespace std;

int real[20][20];
void turn90(int n){
    int buf[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            buf[i][j]=real[n-j-1][i];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            real[i][j]=buf[i][j];
        }
    }
}
int main(void){
    int n,k;
    while(cin>>n>>k){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                char x;
                cin>>x;
                real[i][j]=(x-'0');
            }
        }
        int ars[k][n][n],count=0;
        for(int c=0;c<k;c++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    char x;
                    cin>>x;
                    ars[c][i][j]=x-'0';
                }
            }
        }
        for(int c=0;c<k;c++){
            bool same=false;
            for(int y=0;y<4;y++){
                bool ts=true;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(real[i][j]!=ars[c][i][j])
                            ts=false;
                    }
                }
                if(ts){
                    same=true;
                    break;
                }
                turn90(n);
            }
            if(same)
                count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
