#include <stdio.h>

#define MAX_T 4000000
#define MAX_M 100
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define dd(a) a>0?a:0

int n, m;
int man[MAX_T + 1] = {0}, MaxT = 0;
int DP[MAX_T + MAX_M + 1][2] = {0};
int qz[MAX_T+MAX_M+1]={0};

int main() {
	// freopen("bus.in", "r", stdin);
	// freopen("bus.out","w",stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1, cmp; i <= n; i++) {
		scanf("%d", &cmp);
		man[cmp]++;
		MaxT = max(MaxT, cmp);
	}
	for(int i=1;i<=MaxT+m;i++){
		qz[i]=qz[i-1]+man[i];
	}
	for(int i=1;i<=m;i++){
		DP[i][0]=DP[i-1][0]+qz[i-1];
		DP[i][1]=qz[i];
	}
	for(int i=m+1;i<MaxT+2*m;i++){
		if(DP[i-m][0]+qz[i-1]);
	}
	for(int i=1;i<=MaxT+m;i++){
		printf("%10d%10d\n",DP[i][0],DP[i][1]);
	}
	// printf("%d",DP[MaxT+m][0]);
	return 0;
}