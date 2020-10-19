#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_N 1000
#define MAX_LEN 8

#define MAX(a,b) a>b?a:b


int n, q;
int cmp[MAX_N + 1];
int books[MAX_N + 1][MAX_LEN + 1] = {0};
int IPlen,IPkey;

int qcmp(const void *, const void *);

int main(int argc, char const *argv[])
{
	freopen("librarian.in", "r", stdin);
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cmp[i]);
	}
	qsort(&cmp[1], n, sizeof(cmp[0]), qcmp);
	for (int i = 1; i <= n; i++) {
		int po=10;
		for (int j = 1; j <= MAX_LEN; j++) {
			if(cmp[i]*10/po>0){
				books[i][j] = cmp[i] % po;
			}else{
				books[i][j]=-1;
			}
			po*=10;
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d %d",&IPlen,&IPkey);
		int j=1;
		for(;j<=n;j++){
			if(books[j][IPlen]==IPkey){
				printf("%d\n",cmp[j]);
				break;
			}
		}
		if(j==n+1){
			printf("-1\n");
		}
	}
	return 0;
}

int qcmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}
