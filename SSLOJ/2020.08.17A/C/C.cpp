
#include <stdio.h>
#include <math.h>
#include <set>
#include <bitset>
#include <algorithm>

#define MXN (100020)

int n,m;
std::bitset<MXN>kid,del;
int atk[MXN];

int siz,pos[MXN];

struct Modify{
	int x,w;
}modify[MXN];
struct Query{
	int v,l,r,d;
	bool operator<(const Query M)const{
		if(pos[l]==pos[M.l]){
			if(pos[l]&1)
				return (pos[r]==pos[M.r])?((pos[r]&1)?(v<M.v):(v>M.v)):(pos[r]<pos[M.r]);
			else
				return (pos[r]==pos[M.r])?((pos[r]&1)?(v<M.v):(v>M.v)):(pos[r]>pos[M.r]);
		}else
			return pos[l]<pos[M.l];
	}
}query[MXN];
int v,q;

std::multiset<int>dra;

class Str{
	struct Node{
		short w;
		Node*fr,*to;
	}front,back,*cmp;
	public:
	void build(){
		front.to=&back;
		back.fr=&front;
	}
	bool empty(){return front.to=&back;}
	short bak(){return back.fr->w;}
	short frt(){return front.to->w;}
	void insf(){cmp=(Node*)calloc(sizeof(Node),1),cmp->fr=&front,cmp->to=front.to,front.to=cmp->to->fr=cmp;}
	void insb(){cmp=(Node*)calloc(sizeof(Node),1),cmp->to=&back,cmp->fr=back.fr,back.fr=cmp->fr->to=cmp;}
	void delb(){back.fr=back.fr->fr,back.fr->to=&back;}
	void delf(){front.to=front.to->to,front.to->fr=&front;}
}str;

int ans[MXN];

signed main(){
	freopen("C.in","r",stdin);
	
	str.build();
	
	scanf("%d%d",&n,&m);
		
	for(int i=1,k;i<=n;++i)
		scanf("%d",&k),kid[i]=k;
	for(int i=1;i<=n;++i)
		scanf("%d",&atk[i]);
	
	for(int i=0,o,x,y;i<m;++i){
		scanf("%d%d%d",&o,&x,&y);
		if(o==1)
			modify[++v]=Modify{x,y};
		else
			query[q++]=Query{v,x,y,q};
	}
	
	siz=pow(n,2.0/3.0);
	for(int i=1;i<=n;++i)
		pos[i]=(i-1)/siz+1;
		
	std::sort(query,query+q);
	
	for(int i=0,l=2,x,r=1;i<q;++i){
		while(v<query[i].v){
			++v,x=modify[v].x;
			if(l<=x&&x<=r&&!del[x]){
				dra.erase(dra.find(atk[x]));
				dra.insert(modify[v].w);
				std::swap(atk[x],modify[v].w);
			}
		}
		while(query[i].v<v){
			x=modify[v].x;
			if(l<=x&&x<=r&&!del[x]){
				dra.erase(dra.find(atk[x]));
				dra.insert(modify[v].w);
				std::swap(atk[x],modify[v].w);
			}
			--v;
		}
		while(query[i].l<l){
			--l;
			if(!str.empty()&&(!kid[l])&&str.frt())dra.erase(dra.find(atk[l+1])),del[l]=del[l+1]=1;
			else dra.insert(atk[l]);
		}
		while(r<query[i].r){
			++r;
			if(!str.empty()&&kid[r]&&(!str.bak()))dra.erase(dra.find(atk[r-1])),del[r]=del[r-1]=1;
		}
		while(l<query[i].l){
			
			++l;
		}
		while(query[i].r<r){
			
			--r;
		}
		ans[query[i].d]=(dra.empty())?(0):(*dra.rbegin());
	}
	
	printf("%lf",MXN*sqrt(MXN)*log(MXN));
	
	return 0;
}
