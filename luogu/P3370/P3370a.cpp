// hash 10:53.91

#include <stdio.h>
#include <stdlib.h>

const long long HI = (1<<17)-1,
				HII = 998244353;

char s[2000];

struct Hash{
	int w;
	Hash*next;
}*hash[HI];

long long mHI(char *s){
	long long res=0;
	for(int i=0;s[i];++i)
		res=(res*128+s[i])%HI;
	return res;
}
long long mHII(char *s){
	long long res=0;
	for(int i=0;s[i];++i)
		res=(res*128+s[i])%HII;
	return res;
}
void add_str(char *s){
	Hash*p=NULL;
	int I=mHI(s),II=mHII(s);
	while(!p)p=(Hash*)calloc(sizeof(Hash),1);
	p->w=II;
	p->next=hash[I],hash[I]=p;
}
int count(char *s){
	int I=mHI(s),II=mHII(s);
	for(Hash*i=hash[I];i;i=i->next)
		if(i->w==II)
			return 1;
	return 0;
}

signed main(){
#ifndef ONLINE_JUDGE
	freopen("P3370.in","r",stdin);
#endif

	int n,ans=0;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;++i)
		if(scanf("%s",s),!count(s))
			++ans,add_str(s);
		
	printf("%d",ans);
	
	return 0;
}
