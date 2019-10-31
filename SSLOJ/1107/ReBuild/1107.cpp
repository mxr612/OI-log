#include <stdio.h>
#include <math.h>
// #include <stdlib.h>

int m=-1*'0',n,ans,cmp;

int main(int argc, char const *argv[])
{
	freopen("1107.in","r",stdin);
	m+=getchar();
	for(int t=0;t<m;t++){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			cmp=(int)sqrt(i);
			ans+= cmp*cmp==i;
		}
		printf("%d\n",ans);
	}
	return 0;
}
