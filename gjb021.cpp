#include<iostream>
#include<algorithm>
using namespace std;
struct student{
	int id,math,sum;
	student(){
		
	}
	student(int a,int b,int c){
		id=a;
		math=b;
		sum=c;
	}
};
bool compare(const student& a, const student& b){
	if(a.sum==b.sum){
		return a.math>b.math;
	}
	else
		return a.sum>b.sum;
}
int main(void){
	int n;
	cin>>n;
	student s[n];
	for(int i=0;i<n;i++){
		int a,b,c,d,e,id;
		cin>>id>>a>>b>>c>>d>>e;
		s[i]=student(id,c,a+b+c+d+e);
	}
	sort(s,s+n,compare);
	for(int i=0;i<n;i++){
		cout<<s[i].id<<endl;
	} 
	return 0;
}


