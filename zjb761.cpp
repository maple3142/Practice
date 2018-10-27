#include<iostream>
using namespace std;

/*
0=0
1=1
2=1
3=1
4=0
5=1
6=1
7=1
8=0
...
*/
int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	cout<<(n%4==0?"egg":"fat")<<endl;
	return 0;
}

