#include<stdio.h> 

int n,m;
char map[101][101],cmp;

int  main() {
	freopen("minesweeper.in","r",stdin);
	freopen("minesweeper.out","w",stdout);
	scanf("%d %d",&n,&m);
	getchar(); 
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			map[i][j]='0';
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cmp=getchar();
			if(cmp=='*') {
				for(int a=i-1;a<=i+1;a++) {
					for(int b=j-1;b<=j+1;b++) {
						if(map[a][b]!='*') {
							map[a][b]++;
						}
					}
				}
				map[i][j]='*';
			}
		}
		getchar();
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m+1;j++) {
			putchar(map[i][j]);
		}
		putchar('\n');
	}
	return 0;
} 
