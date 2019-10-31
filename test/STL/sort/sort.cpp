#include<iostream>
#include<cstdio>
#include<algorithm>

struct node{
	int a,b;
};

using namespace std;
int cmd1,cmd2;
struct node s[300];
int p=0;
int d[300];

bool qcmp(node n,node m){
	return n.a==m.a?n.b<m.b:n.a>m.a;
}

int main(){
	freopen("sort.in","r",stdin);
	while(scanf("%d %d",&cmd1,&cmd2)!=EOF){
		p++;
		s[p].a=cmd1;
		s[p].b=cmd2;
	}
//	while(scanf("%d",&d[p])!=EOF)p++;p--;
	putchar('\n');
	sort(s+1,s+p+1,qcmp);
	for(int i=1;i<=p;i++)printf("%-7d %-7d\n",s[i].a,s[i].b);
}
