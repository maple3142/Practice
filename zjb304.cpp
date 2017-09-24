#include<iostream>
#include<stack>
using namespace std;

int main(){
  int n;
  string s;
  stack<char> stk;
  while(cin>>n){
    getchar();
    for(int i=0;i<n;i++){
      getline(cin,s);
      bool correct=true;
      while(!stk.empty())stk.pop();
      for(int j=0;j<s.length();j++){
        if(s[j]=='(' || s[j]=='[')
          stk.push(s[j]);
        else if(s[j] == ')'){
          if(stk.empty() || stk.top()!='('){
            correct=false;
            break;
          }
          stk.pop();
        }
        else if(s[j]==']'){
          if(stk.empty() || stk.top()!='['){
            correct=0;
            break;
          }
          stk.pop();
        }
      }
      if(!stk.empty())correct=false;
      cout<<(correct?"Yes":"No")<<endl;
    }
  }
  return 0;
}
