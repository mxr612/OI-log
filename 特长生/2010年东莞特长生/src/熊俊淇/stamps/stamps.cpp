#include <cstdio>
#include <cctype>
#include <bitset>
#define rr register
using namespace std;
int n,m,a[101]; bitset<26011>f[101];
inline signed iut(){
	rr int ans=0; rr char c=getchar();
	while (!isdigit(c)) c=getchar();
	while (isdigit(c)) ans=(ans<<3)+(ans<<1)+(c^48),c=getchar();
	return ans;
}
signed main(){
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	m=iut(); n=iut();
	for (rr int i=1;i<=n;++i) a[i]=iut();
	for (rr int i=0;i<=m;++i) f[i][0]=1;
	for (rr int i=1;i<=n;++i)
	for (rr int j=1;j<=m;++j)
	    f[j]|=f[j-1]<<a[i];
	for (rr int i=1;i<=26000;++i)
	if (!f[m][i]) return !printf("%d",i-1);
}
