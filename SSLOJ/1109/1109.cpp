#include <stdio.h>
#include <math.h>

int n,m;
double ans;

int main(int argc, char const *argv[])
{
	freopen("1109.in","r",stdin);
	scanf("%d",&n);
	for(int t=1;t<=n;t++){
		ans=0;
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			ans+=log10(i);
		}
		printf("%d\n",((int)ans)+1);
	}
	return 0;
}
