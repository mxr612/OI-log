#include <stdio.h>
#include <string.h>

int m=0-'0',n,ans;
bool room[10001];

int main(int argc, char const *argv[])
{
	freopen("1107.in","r",stdin);
	m+=getchar();
	for (int t = 0; t < m; ++t)
	{
		memset(room,0,sizeof(room));
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;i*j<=n;j++){
				room[i*j]=(room[i*j]+1)%2;
			}
		}
		for(int i=1;i<=n;i++){
			ans+=room[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
