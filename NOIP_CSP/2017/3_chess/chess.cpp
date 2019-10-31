#include <stdio.h>
#include <string.h>

#define MAX_M 100
#define MAX_Q 100000
#define ck(x,y) (x>0)&&(y>0)&&(x<=m)&&(y<=m)
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

int m, n;
int IPx, IPy, IPc;
int mapp[MAX_M + 1][MAX_M + 1] = {0};
int minn[MAX_M + 1][MAX_M + 1];
int que[MAX_Q][3] = {0}, out = 0, in = 1;
int cheak[MAX_M + 1][MAX_M + 1] = {0};
const int way[4][2] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}};

void inq(int,int,int);

int main(int argc, char const *argv[])
{
	freopen("testdata.in", "r", stdin);
	memset(mapp, -1, sizeof(mapp));
	que[0][0] = que[0][1] = 1;
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			minn[i][j] =int(1e10);
		}
	}
	minn[1][0] = minn[1][1] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &IPx, &IPy, &IPc);
		mapp[IPx][IPy] = IPc;
	}
	while (out < in) {
		int x = que[out % MAX_Q][0] , y = que[out % MAX_Q][1],qc=que[out % MAX_Q][2];
		int c = mapp[x][y], v = minn[x][y];
		cheak[x][y] = 0;
		out++;
		for (int w = 0; w < 4; w++) {
			int xx = x + way[w][0], yy = y + way[w][1];
			int cc = mapp[xx][yy];
			if (ck(xx,yy)) {
				if(c==-1){
					if(cc!=-1){
						if(cc==qc){
							if(v<minn[xx][yy]){
								inq(xx,yy,c);
								minn[xx][yy]=v;
							}
						}else{
							if(v+1<minn[xx][yy]){
								inq(xx,yy,c);
								minn[xx][yy]=v+1;
							}
						}
					}
				}else{
					if(cc==c){
						if(v<minn[xx][yy]){
							inq(xx,yy,c);
							minn[xx][yy]=v;
						}
					}else if(cc==-1){
						if(v+2<minn[xx][yy]){
							inq(xx,yy,c);
							minn[xx][yy]=v+2;
						}
					}else{
						if(v+1<minn[xx][yy]){
							inq(xx,yy,c);
							minn[xx][yy]=v+1;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			printf("%11d",minn[i][j]);
		}
		putchar('\n');
	}
	printf("%d", minn[m][m] == int(1e10) ? -1 : minn[m][m]);
	return 0;
}

void inq(int x,int y,int c){
	int pt=in%MAX_Q;
	if(cheak[x][y]==0){
		que[pt][0]=x;
		que[pt][1]=y;
		que[pt][2]=c;
		in++;
	}
}
