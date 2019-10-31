#include <stdio.h>
#include <string.h>

const int way[4][2] = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
int n;
int find[2];
int vi[100000][2], In = 1, Out = 0;
int G[100][100];
int ans[1000][2],flag=0;

void PrintG() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%3d ", G[i][j] % 1000);
		}
		putchar('\n');
	}
	putchar('\n');
}

void PrintAns(int x, int y) {
	if(flag==1){
		return ;
	}
	if(G[x][y]==1){
		printf("(%d,%d)->",x,y );
		for(int i=1;i<G[find[0]][find[1]]-1;i++){
			printf("(%d,%d)->", ans[i][0], ans[i][1]);
		}
		flag=1;
		return ;
	}
	for (int w = 0; w < 4; w++) {
		if (G[x + way[w][0]][y + way[w][1]] == G[x][y] - 1) {
			ans[G[x + way[w][0]][y + way[w][1]]][0]=x;
			ans[G[x + way[w][0]][y + way[w][1]]][1]=y;
			PrintAns(x + way[w][0],y + way[w][1]);
		}
	}
}

int min(int a, int b) {
	return a < b ? a : b;
}

int main(int argc, char const *argv[])
{
	freopen("1128.in", "r", stdin);
	// freopen("1128.out", "w", stdout);
	//InPut-n/start/end
	scanf("%d\n%d %d %d %d\n", &n, &vi[0][0], &vi[0][1], &find[0], &find[1]);
	//Set-G
	memset(G, 0x6f, sizeof(G));
	G[vi[0][0]][vi[0][1]] = 1;
	//In-Map
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (getchar() == '1') {
				G[i][j] = -1;
			}
			getchar();
		}
	}
	while (!(vi[Out][0] == find[0] && vi[Out][1] == find[1])) {
		for (int w = 0; w < 4; w++) {
			if (G[vi[Out][0] + way[w][0]][vi[Out][1] + way[w][1]] != -1 && G[vi[Out][0] + way[w][0]][vi[Out][1] + way[w][1]] > G[vi[Out][0]][vi[Out][1]] + 1) {
				G[vi[Out][0] + way[w][0]][vi[Out][1] + way[w][1]] = G[vi[Out][0]][vi[Out][1]] + 1;
				vi[In][0] = vi[Out][0] + way[w][0];
				vi[In][1] = vi[Out][1] + way[w][1];
				In++;
			}
		}

		Out++;
	}
	PrintAns(find[0], find[1]);
	printf("(%d,%d)\n%d",find[0],find[1], G[find[0]][find[1]]);
	return 0;
}