#include<iostream>
#include<queue>
using namespace std;

int day[100];

int sum(int from,int to){
	int s=0;
	for(int i=from;i<=to;i++)
		s+=day[i];
	return s;
}

int main(void){
	int d;
	while(cin>>d){
		priority_queue<int> q;
		for(int i=0;i<d;i++)
			cin>>day[i];
		for(int i=0;i<d;i++)
			for(int j=0;j<d;j++){
				q.push(sum(i,j));
			}
		cout<<q.top()<<endl;
	}
	return 0;
}


