// ksm 05:07.36

#include <stdio.h>

long long ksm(long long x,long long y,long long m){
	if(m==1)return 0;
	long long res=1;
	while(y){
		if(y&1)(res*=x)%=m;
		(x*=x)%=m;
		y>>=1;
	}
	return res;
}

signed main(){
#ifndef ONLINE_JUDGE
	freopen("P1226.in","r",stdin);
#endif
	
	long long b,p,k;
	
	scanf("%lld%lld%lld",&b,&p,&k);
	
	printf("%lld^%lld mod %lld=%lld",b,p,k,ksm(b,p,k));
	
	return 0;
}
