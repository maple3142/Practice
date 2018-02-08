#include<cstdio>
#include<cstring>
#include<list>
using namespace std;

list<int> q[101];
int main(void){
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF){
		char act[5];
		while(m--){
			scanf("%s",act);
			if(!strcmp(act,"ADD")){
				int i,id;
				scanf("%d %d",&i,&id);
				q[i].push_back(id);
			}
			if(!strcmp(act,"LEAVE")){
				int i;
				scanf("%d",&i);
				if(!q[i].empty())q[i].pop_front();
				else printf("queue %d is empty!\n",i);
			}
			if(!strcmp(act,"JOIN")){
				int i,j;
				scanf("%d %d",&i,&j);
				q[j].splice(q[j].end(),q[i]);
			}
		}
		for(int i=1;i<=n;i++){
			printf("queue %d: ",i);
			if(q[i].empty())printf("empty\n");
			else{
				while(!q[i].empty()){
					printf("%d%s",q[i].front(),(q[i].size()==1?"":" "));
					q[i].pop_front();
				}
				printf("\n");
			}
		}
	}
	return 0;
}

