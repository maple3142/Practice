#include <cstdio>
#include <cstring>
using namespace std;
bool ar[10];
bool check(int num){
    if(num==0)return ar[0];
    while(num>0){
        //printf("num:%d\n",num);
        if(!ar[num%10])return false;
        num/=10;
    }
    return true;
}
int main(){
    int t,n;
    char c;
    scanf("%d",&t);
    while(t--){
        memset(ar,0,sizeof(ar));
        scanf("%d",&n);
        for(int i=0;i<10;i++){
            while(c = getchar())if(c!=' ' && c!='\n')break;
            ar[i] = c-'0';
        }
        for(int i=n;;i++){
            if(check(i)){
                printf("%d\n",i);
                break;
            }
        }
    }
	return 0;
}

