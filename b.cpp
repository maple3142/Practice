#include<stdio.h>
int function1(int );
int function2(int );
int main(){
    int n;
    while(scanf("%d",&n)!=EOF)
    {
      printf("%d\n",function1(n))    ;
    }
}

int function1(int n)
{
    if(n==1)
    return 2;
    else
    return function1(n-1)+function2(n-1);

}
int function2(int n)
{
  if(n==1)
  return 2;
  else
  return  function2(n-1)+n;    



}
