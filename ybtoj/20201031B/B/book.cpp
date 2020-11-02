
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

struct XDS{
	int ll,rr;
	
	struct Node{
		long long c,w;
		Node*ls,*rs;
	}*root;
	
	inline void merge_up(Node*x){
		if(x){
			x->c=x->w=0;
			if(x->ls)x->c+=x->ls->c,x->w+=x->ls->w;
			if(x->rs)x->c+=x->rs->c,x->w+=x->rs->w;
		}
	}
	void insert(Node*&x,int l,int r,const int P,const int W){
		if(r<l||r<P||P<l)return;
		while(!x)x=(Node*)calloc(sizeof(Node),1);
		if(l<r)insert(x->ls,l,(l+r)/2,P,W),insert(x->rs,(l+r)/2+1,r,P,W),merge_up(x);
		else x->w=(x->c+=W)*l;
	}
	
	int cnt(Node*x,int l,int r,const int L,const int R)const{
		if(R<L||r<L||R<l||r<l||!x)return 0;
		return (L<=l&&r<=R)?(x->c):(cnt(x->ls,l,(l+r)/2,L,R)+cnt(x->rs,(l+r)/2+1,r,L,R));
	}
	long long sum(Node*x,int l,int r,const int L,const int R)const{
		if(R<L||r<L||R<l||r<l||!x)return 0;
		return (L<=l&&r<=R)?(x->w):(sum(x->ls,l,(l+r)/2,L,R)+sum(x->rs,(l+r)/2+1,r,L,R));
	}
	
	public:
	
	XDS(){
		ll=1,rr=1e9;
		root=NULL;
	}
	
	void insert(int x,int w){insert(root,ll,rr,x,w);}
	bool query(long long a,long long b){
		return a*b<=b*cnt(root,ll,rr,b,rr)+sum(root,ll,rr,ll,b-1);
	}
};

signed main(){
	
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	
	int n,m;
	char o[5];
	long long a,b;
	int *arr=(int*)calloc(sizeof(int),n+32);

	scanf("%d%d",&n,&m);
	
	if(n*m<=1e7){ // SubII 50pts
		long long s;
		while(m--){
			scanf("%s%lld%lld",o,&a,&b);
			if(!strcmp(o,"U")){
				arr[a]=b;
			}else{
				s=a*b;
				for(int i=1;a>0&&i<=n;++i)
					s-=std::min((long long)arr[i],b);
				printf("%s\n",(s>0)?("NIE"):("TAK"));
			}
		}
	}else{
		XDS xds;
		while(m--){
			scanf("%s%lld%lld",o,&a,&b);
			if(!strcmp(o,"U"))
				xds.insert(arr[a],-1),xds.insert(arr[a]=b,1);
			else
				printf("%s\n",(xds.query(a,b))?("TAK"):("NIE"));
		}
	}
	
	return 0;
}
