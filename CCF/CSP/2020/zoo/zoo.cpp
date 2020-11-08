
#include <stdio.h>

const int MXN = 1000024;

unsigned long long a,aa,bb,cnt;

signed main(){
	
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	
	int n,m,c,k;
	
	scanf("%d%d%d%d",&n,&m,&c,&k);
	
	cnt=k;
	
	for(int i=0;i<n;++i)
		scanf("%llu",&a),aa|=a;

	for(int i=0,p,q;i<m;++i){
		scanf("%d%d",&p,&q);
		if(!(aa&(1<<p)))
			bb|=(1<<p);
	}
	
	for(;bb;bb>>=1)
		if(bb&1)
			--cnt;
	
	printf("%llu",(1<<cnt)-n);		
	
	
	
	return 0;
}
