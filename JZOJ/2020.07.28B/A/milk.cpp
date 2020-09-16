

#define MXN (100020)

#include <stdio.h>
#include <math.h>

int n,q;
int arr[MXN];

inline int div(double x,double y){return floor(x/y);}

signed main(){
	freopen("milk.in","r",stdin);
#ifdef ONLINE_JUDGE
	freopen("milk.out","w",stdout);
#endif
	
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
		scanf("%d",&arr[i]);
		
	printf("%d\n",-4/3);
	
	
	return 0;
}
