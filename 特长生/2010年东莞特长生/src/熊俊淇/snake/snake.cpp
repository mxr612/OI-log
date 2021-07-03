#include <cstdio>
#include <cctype>
#include <algorithm>
#define rr register
using namespace std;
int n,a[101][101],m; 
signed main(){
	freopen("snake.in","r",stdin);
	freopen("snake.out","w",stdout);
	scanf("%d",&n);
	for (rr int i=n*2,dir=0;i>=2;--i,dir^=1){
		if (!dir) for (rr int x=n;x>=1;--x){
			rr int y=i-x; if (y>n) break;
			if (y<1) continue; a[x][y]=++m;
		}else for (rr int x=1;x<=n;++x){
			rr int y=i-x; if (y<1) break;
			if (y>n) continue; a[x][y]=++m;
		}
	}
	for (rr int i=1;i<=n;++i)
	for (rr int j=1;j<=n;++j)
	    printf("%d%c",a[i][j],j==n?10:32);
	return 0;
}
