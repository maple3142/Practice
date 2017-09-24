#include <cstdio>
using namespace std;
int sum,m,ar[30];
bool ok;

void Solve(int now,int nans){
    int chk = nans,chk2 = sum - nans;
    while(chk > 10007)chk -= 10007;
    while(chk2 > 10007)chk2 -= 10007;
    if(chk == chk2 && nans!=0)ok = true;
    if(ok || now >= m)return;
    Solve(now+1,nans+ar[now]);
    Solve(now+1,nans);
}
int main(){
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&ar[i]);
        sum+=ar[i];
    }
    ok = false;
    Solve(0,0);
    if(ok)printf("YES\n");
    else printf("NO\n");
    return 0;
}

