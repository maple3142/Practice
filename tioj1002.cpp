#include<stdio.h>

int main(void){
	int a,b;
	a=getchar()-'0';
	getchar();
	b=getchar()-'0';
	getchar();
	char s[3]={};
	sprintf(s,"%d",a+b);
	puts(s);
	return 0;
}

