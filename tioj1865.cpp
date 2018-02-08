#include"lib1865.h"

//(10^3^2)/2<=500000 
int main(void){
	int n=GetN();
	for(int i=0;i<n-1;i++){
		for(int j=i;j>=0;j--){
			Magic_Operate(j);
		}
	}
	End(); 
	return 0;
}
