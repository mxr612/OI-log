#include<stdio.h>

long a,b,ans=0;

int main() {
	freopen("voldmort.in","r",stdin);
	freopen("voldmort.out","w",stdout);
	scanf("%d %d",&a,&b);
	for(int i=1;i<=b;i++) {
		for(int j=i;j<=b;j+=i) {
			if(j>=a) {
				ans++;
			}
		}
	}
	printf("%ld",ans);
	return 0;
}
