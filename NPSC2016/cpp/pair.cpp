#include<iostream>
#include<set>
using namespace std;

int main(void){
    cin.sync_with_stdio(false);
    int n;
    while(cin>>n){
        set<int> diff;
        for(int u=0;u<n;u++){
            int al;
            cin>>al;
            int A[al];
            for(int i=0;i<al;i++)
                cin>>A[i];
            int bl;
            cin>>bl;
            int B[bl];
            for(int i=0;i<bl;i++)
                cin>>B[i];
            if(al>bl)
                for(int Aidx=0,Bidx=0;Aidx<al&&Bidx<bl;Aidx++){
                    if(A[Aidx]==B[Bidx]){
                        Bidx++;
                    }
                    else
                        diff.insert(A[Aidx]);
                }
            else
                for(int Aidx=0,Bidx=0;Aidx<al&&Bidx<bl;Aidx++){
                    if(A[Aidx]==B[Bidx]){
                        Aidx++;
                    }
                    else
                        diff.insert(B[Bidx]);
                }
        }
        cout<<diff.size()<<endl;
    }
    return 0;
}
