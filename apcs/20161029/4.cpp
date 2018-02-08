#include<iostream>
#include<vector>
using namespace std;

vector<string> hit[10];
struct Player{
	int place;
};
int main(void){
	ios::sync_with_stdio(false);
	for(int i=1;i<=9;i++){
		int n;
		cin>>n;
		string s;
		while(n--){
			cin>>s;
			hit[i].push_back(s);
		}
	}
	int b;
	cin>>b;
	
	return 0;
}

