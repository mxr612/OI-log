// P1020
// testdata

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//题意
int hi[100001] = {0}, end = 0;

//离散
int ls[100001] = {0}, top_val;
int _lsh(int arr[], int ls[], int size);

//树状
int tree[100001] = {0};
#define lowbit(n) ((n)&(-n))
void tree_update(int tree[], int size, int node, int val);
#define max(m,n) (m>n?m:n)
int tree_max(int tree[], int node);

int main() {
	freopen("testdata.in", "r", stdin);

	while (scanf("%d", &hi[++end]) != EOF); end--;
	top_val = _lsh(hi, ls, end);

	for (int i = end; i > 0; i--)
		tree_update(tree, top_val, ls[i] , tree_max(tree, ls[i]) + 1);
	printf("%d\n", tree_max(tree,top_val));

	memset(tree, 0, sizeof(tree));
	for (int i = 1; i <= end; i++)
		tree_update(tree, top_val, ls[i] , tree_max(tree, ls[i] - 1) + 1);
	printf("%d", tree_max(tree,top_val));

	return 0;
}

struct nodeS {int id, vl;};//离散专用str
int cmpS(const void *m, const void *n) {return (*(struct nodeS *)m).vl > (*(struct nodeS *)n).vl;}//离散专用str的排序cmp
int _lsh(int arr[], int ls[], int size) {//离散
	struct nodeS cmp[100001];
	for (int i = 1; i <= size; i++) {
		cmp[i].id = i;
		cmp[i].vl = arr[i];
	}
	qsort(&cmp[1], size, sizeof(cmp[0]) , cmpS);
	for (int i = 1, lsz = 1; i <= size; i++) {
		ls[cmp[i].id] = lsz;
		if (cmp[i + 1].vl > cmp[i].vl)
			lsz++;
	}
	return ls[cmp[size].id];
}

void tree_update(int tree[], int size, int node, int val) {
	for (; node <= size; node += lowbit(node))
		tree[node] = max(tree[node], val);
}
int tree_max(int tree[], int node) {
	int ans = 0;
	for (; node > 0; node -= lowbit(node))
		ans = max(ans, tree[node]);
	return ans;
}
