#include<iostream>
#include<cstring>
#define MOD 100000007
typedef long long int LL;
using namespace std;
int B[2][2]={{0,1},
		     {1,1}};
int Bn[2][2]={{0,1},
		      {1,1}};
void Fast(int n){
	int arr[2][2];
	if(n==1){return;}
		int tmp[2][2];
		memset(tmp,0,sizeof(tmp));
		Fast(n/2);
		for(int k = 0 ; k < 2 ; k++){
			for(int i = 0 ; i < 2 ; i++){
				for(int j = 0 ; j < 2 ; j++){
					tmp[i][j] += ((LL)Bn[i][k] * (LL)Bn[k][j])%MOD;
					tmp[i][j]%=MOD;
				}
			}
		}
		memset(Bn,0,sizeof(Bn));
		if(n%2==1)
			for(int k = 0 ; k < 2 ; k++){
				for(int i = 0 ; i < 2 ; i++){
					for(int j = 0 ; j < 2 ; j++){
						Bn[i][j] += tmp[k][j] * B[i][k];
						Bn[i][j]%=MOD; 
					}
				}
			}
		else
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
					Bn[i][j]=tmp[i][j];
}
int main(void){
	int m,f,k,sum;
	while(cin>>m>>f>>k){
		Bn[0][0]=0,Bn[0][1] = Bn[1][0] = Bn[1][1] = 1;
		Fast(k);
		/*   n     |m|
		    B  *   |f|   */
		sum=((LL)m*Bn[0][0]%MOD + (LL)f*Bn[0][1]%MOD + (LL)m*Bn[1][0]%MOD + (LL)f*Bn[1][1])%MOD;
		cout<<sum<<endl;
	}
	return 0;
}
