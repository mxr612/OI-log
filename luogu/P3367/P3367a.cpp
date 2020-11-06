// bin 08:05.13

#include <stdio.h>
#include <stdlib.h>

class Bin{
	
	int *frm,*siz;
	
	int find(int x){return (frm[x]==x)?(x):(frm[x]=find(frm[x]));}

	public:
	Bin(int n){
		frm=(int*)calloc(sizeof(int),n+32);
		siz=(int*)calloc(sizeof(int),n+32);
		for(int i=1;i<=n;++i)
			frm[i]=i;
	}
	
	bool is_same(int x,int y){return find(x)==find(y);}
	
	void merge(int x,int y){
		if(is_same(x,y))return;
		x=find(x),y=find(y);
		if(siz[x]<siz[y])x^=y^=x^=y;
		siz[x]+=siz[y];
		frm[y]=x;
	}
	
};

signed main(){
#ifndef ONLINE_JUDGE
	freopen("P3367.in","r",stdin);
#endif

	int N,M;
	
	scanf("%d%d",&N,&M);
	
	Bin bin(N);
	
	for(int i=0,o,x,y;i<M;++i)
		if(scanf("%d%d%d",&o,&x,&y),o==1)
			bin.merge(x,y);
		else
			printf("%c\n",(bin.is_same(x,y))?('Y'):('N'));
	
	return 0;
}
