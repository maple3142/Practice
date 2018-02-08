#include<stack>
#include<queue>
using namespace std;
void push_train();
void move_station_1_to_2();
void move_station_2_to_1();
void pop_train();
void no_solution();
void solve(int n,int order[]){
	stack<int> s1,s2;
	queue<int> in,odr;
	for(int i=0;i<n;i++){
		odr.push(order[i]);
		in.push(i+1);
	}
	while(!odr.empty()||!in.empty()){
		if(s1.empty()&&s2.empty()){
			s1.push(in.front());
			in.pop();
			push_train();
		}
		else if(odr.front()==s1.top()){
			odr.pop();
			s1.pop();
			move_station_1_to_2();
			pop_train();
		}
		else if(odr.front()==s2.top()){
			odr.pop();
			s2.pop();
			pop_train();
		}
		else if(odr.front()==in.front()){
			odr.pop();
			in.pop();
			push_train();
			move_station_1_to_2();
			pop_train();
		}
		else if(!in.empty()){
			s1.push(in.front());
			in.pop();
			push_train();
		}
		else{
			if(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
				move_station_1_to_2();
			}
			else{
				s1.push(s2.top());
				s2.pop();
				move_station_2_to_1();
			}
		}
	}
}
