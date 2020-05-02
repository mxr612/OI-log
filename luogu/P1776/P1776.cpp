/**
 * luogu P1776
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>

#define MXN (1000020)
#define MXW (400020)

int n,W;
int v,w,m;

int vv[MXN],ww[MXN],t=0;
int DP[MXW]={0},ans=0;

signed main(){

#ifndef ONLINE_JUDGE
	freopen("P1776.in","r",stdin);
#endif

	scanf("%d%d",&n,&W);

	for(int i=0,j;i<n;++i){
		for(scanf("%d%d%d",&v,&w,&m),j=1;m>=j;m-=j,j<<=1,++t)
			vv[t]=j*v,ww[t]=j*w;
		if(m>0)
			vv[t]=m*v,ww[t]=m*w,++t;
	}

	for(int i=0,j;i<t;++i)
		for(j=W;j>=ww[i];--j)
			ans=std::max(ans,DP[j]=std::max(DP[j],DP[j-ww[i]]+vv[i]));
	
	printf("%d",ans);

	return 0;
}