#include<queue>
#include<unordered_map>
#include"lib1168.h"
using namespace std;

priority_queue<int> M,m;
unordered_map<int,int> rm;
void pop_big(){
	while(!rm[M.top()]){
		M.pop();
	}
	rm[M.top()]--;
	if(!M.empty())M.pop();
}
void pop_small(){
	while(!(rm[m.top()*-1])){
		m.pop();
	}
	rm[m.top()*-1]--;
	if(!m.empty())m.pop();
}
void push(int s){
	M.push(s);
	m.push(s*-1);
	rm[s]++;
}
int big(){
	while(!rm[M.top()]){
		M.pop();
	}
	return M.top();
}
int small(){
	while(!(rm[m.top()*-1])){
		m.pop();
	}
	return m.top()*-1;
}
