#include <stdio.h>
#include <stdlib.h>

int m,n,ans=0,pl=0;
int man_n[20001]={0},man_m[20001]={0};

int qcmp(const void *a,const void *b){
	return *(int *)a-*(int *)b;
}

int main(int argc, char const *argv[])
{
	freopen("1104.in","r",stdin);
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++){
		scanf("%d",&man_m[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&man_n[i]);
	}
	qsort(&man_m[1],m,sizeof(man_m[0]),qcmp);
	qsort(&man_n[1],n,sizeof(man_n[0]),qcmp);
	for(int i=1;i<=m;i++){
		while(pl<=n&&man_m[i]>man_n[pl])pl++;
		ans+=pl-1;
	}
	printf("%d",ans);
	return 0;
}
