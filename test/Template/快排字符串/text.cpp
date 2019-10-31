/**
 * 第一行输入N代表字符串的数量
 * 2-N+1行输入N个字符串
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max_Char 256
#define Max_N 100

struct str
{
	char s[Max_Char];
}qs[Max_N];

int N;

int qcmp(const void *a,const void *b){
	return strcmp((*(struct str *)a).s,(*(struct str *)b).s);
}

int main(int argc, char const *argv[])
{
	freopen("text.in","r",stdin);
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%s\n",qs[i].s);
	}
	qsort(&qs[0],N,sizeof(qs[0]),qcmp);
	for(int i=0;i<N;i++){
		printf("%s\n",qs[i].s);
	}
	return 0;
}

//结论
//字符数组快排需要使用结构体，再利用strcmp判断大小
//默认升序，可以乘-1变降序
//
//strcmp优先字母排序，前缀相同的较长者置后