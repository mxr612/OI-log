// 1

#include <stdio.h>

int n;
// 转码最长升
int T[110000];
int a[110000];
// 树状数
int tree[110000*4]={0};
#define lowbit(_N_) (_N_&(-_N_))
#define max(__M__,__N__) ((__M__)>(__N__)?(__M__):(__N__))
void update(int ht,int vl){
	for(;ht<=n;ht+=lowbit(ht))
		tree[ht]=max(tree[ht],vl);
}
int get(int ht){
	int ret=0;
	for(;ht>0;ht-=lowbit(ht))
		ret=max(ret,tree[ht]);
	return ret;
}


int main(){

	freopen("1.in","r",stdin);

	scanf("%d",&n);

	for(int i=1,cmp;i<=n;++i)
		scanf("%d",&cmp),T[cmp]=i;
	for(int i=1,cmp;i<=n;++i)
		scanf("%d",&cmp),a[i]=T[cmp];

	for(int i=n;i>0;--i)
		update(a[i],get(a[i]-1)+1);

	printf("%d",get(n));

	return 0;
}