#include <stdio.h>
#include <string.h>

const int way[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
int n,m;
char nm[101][101];
int AZ[129][2][2]={0};
int que[30000][2],In=1,Out=0;

int main(int argc, char const *argv[])
{
	freopen("83.in","r",stdin);
	memset(nm,0,sizeof(nm));
	scanf("%d %d\n",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			nm[i][j]=getchar();
			if(nm[i][j]=='0'){
				nm[i][j]=-1;
			}else if(nm[i][j]=='1'){
				nm[i][j]=-2;
			}else if(AZ[(int )nm[i][j]][0][0]==0){
				AZ[(int )nm[i][j]][0][0]=i;
				AZ[(int )nm[i][j]][0][1]=j;
			}else{
				AZ[(int )nm[i][j]][1][0]=i;
				AZ[(int )nm[i][j]][1][1]=j;
			}
		}
		getchar();
	}

	que[0][0]=que[0][1]=1;
	nm[1][1]=0;
	while(Out<In&&nm[n][m]==-1){
		for(int i=0;i<4;i++){
			int x=que[Out][0]+way[i][0],y=que[Out][1]+way[Out][1];
			if(nm[x][y]>='A'&&nm[x][y]<='Z'){
				x=AZ[(int)nm[x][y]][0][0]==x?AZ[(int )AZ[x][y]][1][0]:AZ[(int)nm[x][y]][0][0];
				y=AZ[(int)nm[x][y]][0][0]==y?AZ[(int )AZ[x][y]][1][1]:AZ[(int)nm[x][y]][0][1];
				
			}
			if(nm[x][y]==-1){
				que[In][0]=x;
				que[In][1]=y;
				nm[x][y]=nm[que[Out][0]][que[Out][1]]+1;
				In++;
			}
		}
		Out++;
	}
	if(In==Out){
		printf("No Solution.");
	}else{
		printf("%d", nm[n][m]);
	}
	return 0;
}