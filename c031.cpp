#include <stdio.h>
#include <set>
using namespace std;

	int main() {
		int all,n,k;
		while(scanf("%d %d %d",&all,&n,&k)!=EOF){
			std::set<int> num;
			for(int i=1;i<=all;i++)
				num.insert(i);
			int i=n;
			while(num.size()>all-k+1){
				num.erase(i);
				int count=0;
				while(count<n){
					if(i>=all)
						i%=all;
					i++;
					if(num.find(i) != num.end())
						count++;
				}
			}
			printf("%d\n",i-1);
		}
		return 0;
	}
