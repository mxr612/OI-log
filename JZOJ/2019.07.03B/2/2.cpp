// 2

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n,t;

int top=0;
struct edge{int fr,to;}E[200000],S[200000];

int cmpS(const void *m,const void *n){
	if((*(edge *)m).fr==(*(edge *)n).fr)
		return (*(edge *)m).to>(*(edge *)n).to;
	return (*(edge *)m).fr>(*(edge *)n).fr;
}

struct node{
	bool empty;
	int d,l,r;
}tree[100001];

bool vis[100001]={false};
int cnt=0;
void dfs(int id){//寻找父子关系/寻找有向边(向儿子)
	for(int i=tree[id].l;i<=tree[id].r;++i){
		if(!vis[E[i].to]){
			vis[E[i].to]=true;
			tree[E[i].to].d=id;
			S[++top]=E[i];
			dfs(E[i].to);
		}
	}
}

int go(int id){//
	for(int i=tree[id].l;i<=tree[id].r;++i){
		if(tree[S[i].to].empty)
			return S[i].to;
	}
	return -1;
}

int sovle1(int x){
	int p;
	for(int i=1;i<=x;++i){
		p=1;
		while(go(p)>0)p=go(p);
		tree[p].empty=false;
	}
	return p;
}

int sovle2(int x){
	int p=0;
	while(!tree[tree[x].d].empty){
		x=tree[x].d;
		p++;          
	}
	tree[x].empty=true;
	return p;
}

int main(){

	freopen("2.in","r",stdin);

	scanf("%d %d",&n,&t);
	for(int i=1,a,b;i<n;++i){
		scanf("%d %d",&a,&b);
		E[i]={a,b};
		E[n-1+i]={b,a};
	}

	qsort(&E[1],2*n-2,sizeof(E[1]),cmpS);
	for(int i=1;i<=2*n;++i){
		if(E[i].fr!=E[i-1].fr){
			tree[E[i-1].fr].r=i-1;
			tree[E[i].fr].l=i;
		}
	}

	vis[1]=true;
	dfs(1);
	qsort(&S[1],n-1,sizeof(S[1]),cmpS);
	for(int i=0;i<=n;++i){
		tree[i].empty=true;
		tree[i].l=0;
		tree[i].r=-1;
	}
	for(int i=1;i<=2*n;++i){
		if(S[i].fr!=S[i-1].fr){
			tree[S[i-1].fr].r=i-1;
			tree[S[i].fr].l=i;
		}
	}


	for(int i=1,op,x;i<=t;++i){
		scanf("%d %d",&op,&x);
		printf("%d\n",op==1?sovle1(x):sovle2(x));
	}

	return 0;
}