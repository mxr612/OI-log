// P1972.in


#include <stdio.h>
#include <stdlib.h>

int N, M, n;
int id[500001] = {0};
int lsh(int arr[], int size);

struct bt {
	int id, fr, to,ans;
} m[500001];
#define l (m[i].fr)
#define r (m[i].to)
int cmpSa(const void *m, const void *n) {return (*(struct bt *)m).fr > (*(struct bt *)n).fr;}
int cmpSb(const void *m, const void *n) {return (*(struct bt *)m).id > (*(struct bt *)n).id;}


int sum[500001] = {0};
int L = 0, R = 0;

int tree[500001] = {0};
#define lowbit(n) (n&(-n))
void tree_update(int tree[], int size, int node, short val);
int tree_sum(int tree[], int size);

int main() {
	freopen("P1972.in", "r", stdin);

	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &id[i]);
	n = lsh(id, N);
	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d %d\n", &m[i].fr, &m[i].to);
		m[i].id = i;
	}

	qsort(&m[1],M,sizeof(m[0]),cmpSa);

	for (int i = 1; i <= M; i++) {
		while (L < l)tree_update(tree, n, id[L++], -1);
		while (R < r)tree_update(tree, n, id[++R], 1);
		while (r < R)tree_update(tree, n, id[R--], -1);
		m[i].ans=tree_sum(tree, n);
	}

	qsort(&m[1],M,sizeof(m[0]),cmpSb);

	for (int i = 1; i <= M; i++) {
		printf("%d\n", m[i].ans);
	}

	return 0;
}

struct nodeL {int id, vl;} cmp[500001];
int cmpS(const void *m, const void *n) {return (*(struct nodeL *)m).vl > (*(struct nodeL *)n).vl;}
int lsh(int arr[], int size) {
	for (int i = 1; i <= size; i++) {
		cmp[i].id = i;
		cmp[i].vl = arr[i];
	}
	qsort(&cmp[1], size, sizeof(cmp[0]), cmpS);
	for (int i = 1, lsz = 1; i <= size; i++) {
		arr[cmp[i].id] = lsz;
		if (cmp[i].vl < cmp[i + 1].vl)
			lsz++;
	}
	return arr[cmp[size].id];
}

void tree_update(int tree[], int size , int node, short val) {
	sum[node] += val;
	if (sum[node] == 0)
		for (; node <= size; node += lowbit(node))
			tree[node]--;
	else if (sum[node] == 1)
		for (; node <= size; node += lowbit(node))
			tree[node]++;
}
int tree_sum(int tree[], int size) {
	int ans = 0;
	for (; size > 0; size -= lowbit(size))
		ans += tree[size];
	return ans;
}