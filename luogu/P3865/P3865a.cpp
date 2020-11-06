// P3865 ST 07:17.67

#include <stdio.h>
#include <math.h>
#include <algorithm>

const int MXN = 100024;

int st[MXN][20];

signed main(){
#ifndef ONLINE_JUDGE
	freopen("P3865.in","r",stdin);
#endif

	int N,M;
	
	scanf("%d%d",&N,&M);
	
	for(int i=1;i<=N;++i)
		scanf("%d",&st[i][0]);
	
	for(int i=0,ii=1,j;i<=log2(N);++i,ii<<=1)
		for(j=1;j+ii<=N;++j)
			st[j][i+1]=std::max(st[j][i],st[j+ii][i]);
			
	for(int i=0,l,r,s,ss;i<M;++i)
		scanf("%d%d",&l,&r),
		ss=1<<(s=log2(r-l+1)),
		printf("%d\n",std::max(st[l][s],st[r-ss+1][s]));

	return 0;
}
