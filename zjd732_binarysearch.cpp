#include<cstdio>

int ar[100000+5];
int find(int l,int r,int q){
	if(l==r && ar[l]==q)return l;
	else if(l==r)return 0;
	int mid=(l+r)/2;
	if(q>ar[mid]) return find(mid+1,r,q);
	else return find(l,mid,q);
}
int main(void){
	int n,k,f;
	while(scanf("%d %d",&n,&k)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&ar[i]);
		}
		for(int i=1;i<=k;i++){
			scanf("%d",&f);
			printf("%d\n",find(1,n,f));
		}
	}
	return 0;
}


