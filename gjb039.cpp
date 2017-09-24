#include<cstdio>
using namespace std;

bool used[20];
int res[20];
int n;
int abs(int x){
	return (x<0?-1*x:x);
}
void backtrack(int x){
	bool flag=true;
	for(int i=n-x;i>x && flag;i--){
		for(int j=i-1;j>x;j--){
			if(i-j==abs(res[j]-res[i])){
				flag=false;
				break;
			}
		}
	}
	if(!flag)return;
	if(x!=0){
		for(int i=1;i<=n;i++){
			if(!used[i]){
				used[i]=true;
				res[x]=i;
				backtrack(x-1);
				used[i]=false;
			}
		}
		return;
	}
	for(int i=n;i>0;i--)
		printf("%d ",res[i]);  
	printf("\n"); 
}
int main(void){
	while(scanf("%d",&n)!=EOF){
		backtrack(n);
	}
	return 0;
}

