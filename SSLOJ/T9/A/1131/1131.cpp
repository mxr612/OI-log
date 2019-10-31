#include <stdio.h>
#include <string.h>

int m, n;

/**
 * sta-车站转乘
 * line-车站_线路-对应
 */

int sta[501], line[101][501] = {0};
int vi[501], In = 1, Out = 0;

int main(int argc, char const *argv[])
{
	//Set
	freopen("1131.in", "r", stdin);
	memset(sta, -1, sizeof(sta));
	vi[0]=1;
	sta[1]=0;
	//In
	scanf("%d %d", &m, &n);
	for (int i = 1, ip; i <= m; i++) {
		do {
			scanf("%d", &ip);
			line[i][ip] = 1;
		} while (getchar() == ' ');
	}
	//BFS
	while(vi[Out]!=n){
		for(int i=1;i<=m;i++){
			if(line[i][vi[Out]]==1){
				for(int j=1;j<=n;j++){
					if(line[i][j]==1&&sta[j]==-1){
						vi[In]=j;
						sta[j]=sta[vi[Out]]+1;
						In++;
					}
				}
			}
		}
		Out++;
	}
	printf("%d\n", sta[n]);
	return 0;
}