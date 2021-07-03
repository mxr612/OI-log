#include <cstdio>
#include <cctype>
#include <algorithm>
#define rr register
using namespace std;
struct rec{int rk,w;}a[201]; int n;
inline signed iut(){
	rr int ans=0; rr char c=getchar();
	while (!isdigit(c)) c=getchar();
	while (isdigit(c)) ans=(ans<<3)+(ans<<1)+(c^48),c=getchar();
	return ans;
}
bool cmp(rec x,rec y){return x.w!=y.w?x.w>y.w:x.rk<y.rk;}
signed main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	n=iut(),a[0].w=-1;
	for (rr int i=1;i<=n;++i)
	    a[i]=(rec){iut(),iut()};
	sort(a+1,a+1+n,cmp);
	for (rr int i=1,now=0;i<=n;++i)
	    now=a[i].w==a[i-1].w?now+1:0,
	    printf("%d %d %d\n",a[i].rk,a[i].w,i-now);
	return 0;
}
