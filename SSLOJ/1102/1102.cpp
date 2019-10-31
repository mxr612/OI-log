#include <stdio.h>
#include <stdlib.h>

long long read();
int qcmp_in(const void *,const void *);
int qcmp_box(const void *,const void *);
int find(int)


struct box
{
	int l[11];
}boxes[10001]={0};

int k=0,n=0;
int tr[10001],top=0;

int main(int argc, char const *argv[])
{
	freopen("1102.in","r",stdin);
	k=read();
	n=read();
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			boxes[i].l[j]=read();
		}
		qsort(&boxes[i].l[1],n,sizeof(boxes[i].l[0]),qcmp_in);
	}
	qsort(&boxes[1],k,sizeof(boxes[0]),qcmp_box);
	for(int i=1;i<=k;i++){
		for(int j=1;j<=)
	}
	return 0;
}

long long read(){
	int f=1;
	char c;
	long long s = 0;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return f*s;
}

int qcmp_in(const void *a,const void *b){
	return (*(int *)a)-(*(int *)b);
}

int qcmp_box(const void *a,const void *b){
	return (*(box *)a).l[1]-(*(box *)b).l[1];
}
