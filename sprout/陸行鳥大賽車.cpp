#include<cstdio>
using namespace std;

const int MAX=100001;
int front[MAX],back[MAX];
int main(void){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			front[i]=i-1;
			back[i]=i+1;
		}
		int m,st=1,ed=n;
		scanf("%d",&m);
		while(m--){
			int t,x;
			scanf("%d %d",&t,&x);
			int f=front[x],b=back[x];
			if(t==0){
				if(x==st)st=b;
				if(x==ed)ed=f;
				front[b]=f;
				back[f]=b;
				front[x]=back[x]=0;
			}
			else{
				if(x==ed)ed=f;
				if(x!=st){
					if(f==st)st=x;
					back[front[f]]=x;
					back[f]=b;
					front[b]=f;
					front[x]=front[f];
					back[x]=f;
					front[f]=x;
				}
			}
			/*cout<<st<<"  "<<ed<<endl;
			for(int i=1;i<=n;i++){
				cout<<front[i]<<" ";
			}
			cout<<endl;
			for(int i=1;i<=n;i++){
				cout<<back[i]<<" ";
			}
			cout<<endl;*/
		}
		while(st!=ed){
			printf("%d ",st);
			st=back[st];
		}
		printf("%d\n",ed);
	return 0;
}

