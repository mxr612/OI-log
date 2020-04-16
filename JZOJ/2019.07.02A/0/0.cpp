// 0

#include <stdio.h>

int n,r;

struct node{
	int id;
	struct node *fr,*to;
}P[710000];
struct node *pt;


int main(){

	freopen("0.in","r",stdin);
	freopen("0.out","w",stdout);

	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		P[i].id=i;
		P[i].fr=&P[i-1];
		P[i].to=&P[i+1];
	}
	P[1].fr=&P[n];
	pt=P[n].to=&P[1];

	for(int i=n;i>0;--i){
		scanf("%d",&r);
		for(int j=1;j<=r%i;++j)
			pt=pt->to;
		printf("%d\n",pt->id);
		// printf("%d\n",i);
		pt->fr->to=pt->to;
		pt->to->fr=pt->fr;
		pt=pt->to;
	}

	return 0;
}