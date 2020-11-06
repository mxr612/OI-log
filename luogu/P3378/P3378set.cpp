// set heap 05:11.76
// std::multiset 

#include <stdio.h>
#include <set>

signed main(){
#ifndef ONLINE_JUDGE
	freopen("P3378.in","r",stdin);
#endif

	int n;
	std::multiset<int>set;

	scanf("%d",&n);
	
	for(int i=0,o,x;i<n;++i){
		scanf("%d",&o);
		switch(o){
			case 1:
				scanf("%d",&x);
				set.insert(x);
				break;
			case 2:
				printf("%d\n",*set.begin());
				break;
			case 3:
				set.erase(set.begin());
				break;
			default:;
		}
	}
	
	return 0;
} 
