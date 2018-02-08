#include<stdio.h>

int T,k;
char s[100001];
int cnt[26];
int mxc[26];
inline int max(int a,int b){
	return a>b?a:b;
}
int main(void){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&k,&s);
		int mx=0;
		for(int i=0;i<k;i++){
			cnt[s[i]-'a']++;
			mx=max(mx,cnt[s[i]-'a']);
		}
		for(int i=0;i<26;i++){
			if(cnt[i]==mx){
				printf("%c",'a'+i);
			}
			cnt[i]=0;
		}
		puts("");
	}
	return 0;
}

