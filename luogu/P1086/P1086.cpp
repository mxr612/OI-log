
//testdata.in
//P1086.in
#include <stdio.h>
#include <stdlib.h>

#define LL long long

struct nut
{
	int x,y;
	int v;
}nuts[500];

void read_num(void *);
unsigned int JD(signed int);
int qcmp(const void *,const void *);

int M,N,K,ans=0,p=0;

int main(int argc, char const *argv[])
{
	// freopen("P1086.in","r",stdin);
	read_num(&M);
	read_num(&N);
	read_num(&K);
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			p++;
			read_num(&(nuts[p].v));
			nuts[p].x=i;
			nuts[p].y=j;
		}
	}

	qsort(&nuts[1],N*M,sizeof(nuts[0]),qcmp);
	nuts[0].x=nuts[1].x;
	nuts[0].y=nuts[1].y;
	K-=nuts[1].x;
	for(int i=1;(nuts[i].x+JD(nuts[i].x-nuts[i-1].x)+JD(nuts[i].y-nuts[i-1].y))+1<=K&&i<=M*N;i++){
		// printf("%d+%d<=%d\n",nuts[i].x,JD(nuts[i].x-nuts[i-1].x)+JD(nuts[i].y-nuts[i-1].y),K);
		K-=JD(nuts[i].x-nuts[i-1].x)+JD(nuts[i].y-nuts[i-1].y)+1;
		ans+=nuts[i].v;
	}
	printf("%d",ans);
	return 0;
}

void read_num(void *ans){
	char c;
	int f=1;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f= -1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		(*(int *)ans)=(*(LL *)ans)*10+c-'0';
		c=getchar();
	}
	(*(int *)ans)*=f;
}

int qcmp(const void *a,const void *b){
	return (*(struct nut *)b).v-(*(struct nut *)a).v;
}

unsigned int JD(signed int InPut){
	return InPut<0?-1*InPut:InPut;
}
