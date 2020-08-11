
#define MXN (100020)

#include <stdio.h>

#include <vector>

long long n,k;

struct Edge{
	int u,v,w;
};

std::vector<Edge>A[MXN];

signed main(){
	freopen("C.in","r",stdin);
	
	scanf("%lld%lld",&n,&k);
	
	if(n*n<k){
		printf("Stupid Mike");
		return 0;	
	}
	
	return 0;
}
