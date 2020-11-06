// pq heap 03:44.59 

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

signed main(){
#ifndef ONLINE_JUDGE
freopen("P3378.in","r",stdin);
#endif
	
	int n;
	
	scanf("%d",&n);
	
	std::priority_queue<int,std::vector<int>,std::greater<int> >pq;
	
	for(int i=0,o,x;i<n;++i){
		scanf("%d",&o);
		switch(o){
			case 1:
				scanf("%d",&x);
				pq.push(x);
				break;
			case 2:
				printf("%d\n",pq.top());
				break;
			case 3:
				pq.pop();
				break;
			default:;
		}
	}
	
	return 0;
} 
