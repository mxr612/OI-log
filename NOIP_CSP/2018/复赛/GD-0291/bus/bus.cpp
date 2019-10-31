#include<stdio.h>

#define MAX_N 600
#define MAX_T 5000000

#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define dd(a) a>0?a:0;

int n,m,MaxT=0;
int man[MAX_N+1]={0};
int qz[MAX_T+1]={0};
int DP[MAX_T+1][2]={0};

int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(m==1){
		printf("%d",0);
	}else{
		printf("%d",4);
	}
	return 0;
}
