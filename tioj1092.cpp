#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int n,e;
struct node{
	vector<int> v;
	bool win;
	node(){
		win=false;
	}
	void to(int a){
		v.push_back(a);
	}
};
node a[10001];
void dfs(int now,bool destwin){
	if(!destwin){
		a[now].win=true;
	}
	if(a[1].win)return;
	for(auto i:a[now].v){
		dfs(i,a[now].win);
	}
}
int main(void){
	while(scanf("%d%d",&n,&e)!=EOF){
		if(n==0&&e==0)break;
		for(int i=1;i<=e;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			a[y].to(x);
		}
		a[n].win=true;
		dfs(n,false);
		char s[10];
		scanf("%s",s);
		if(n==1){
			printf("%s\n",s);
		}
		else
			if(a[1].win){
				if(strcmp(s,"Mimi"))
					printf("Mimi\n");
				else
					printf("Moumou\n");
			}
			else{
				if(strcmp(s,"Mimi"))
					printf("Moumou\n");
				else
					printf("Mimi\n");
			}
		for(auto b:a){
			b.v.clear();
			b.win=false;
		}
	}
	return 0;
}


