// P5275.in

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, top;

struct sta {
	int id, a, b, ls, fr;
} star[100001];
struct node {
	int vl, id;
} tree[100001] = {0}, cmp;

int cmpA(sta m, sta n) {if (m.a == n.a)return m.b > n.b; else return m.a < n.a;}
int cmpB(sta m, sta n) {return m.b < n.b;}
int cmpID(sta m, sta n) {return m.id < n.id;}

#define lb(n) (n&(-n))
struct node get(int pt) {
	struct node ret = tree[pt];
	for (pt += lb(pt); pt <= top; pt += lb(pt)) {
		if (ret.vl < tree[pt].vl)
			ret = tree[pt];
	}
	return ret;
}
void update(int pt, struct node vl) {
	for (; pt > 0; pt -= lb(pt)) {
		if (vl.vl > tree[pt].vl)
			tree[pt] = vl;
	}
}
void print(int dep) {
	if (star[dep].fr > 0)
		print(star[dep].fr);
	cout << star[dep].id << ' ';
}

int main() {
	freopen("P5275.in", "r", stdin);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> star[i].a;
	for (int i = 1; i <= N; i++)
		cin >> star[i].b;
	for (int i = 1; i <= N; i++)
		star[i].id = i;
	sort(&star[1], &star[N + 1], cmpB);
	for (int i = 1, lsz = 1; i <= N; i++) {
		star[i].ls = lsz;
		if (star[i].b != star[i + 1].b)lsz++;
	}
	top = star[N].ls;
	sort(&star[1], &star[N + 1], cmpA);
	memset(tree, 0, sizeof(tree));

	for (int i = 1; i <= N; i++) {
		cmp = get(star[i].ls);
		star[i].fr = cmp.id;
		cmp.id = star[i].id;
		cmp.vl++;
		update(star[i].ls, cmp);
	}

	sort(&star[1], &star[N + 1], cmpID);
	cmp = get(1);
	cout << cmp.vl << endl;
	print(cmp.id);

	return 0;
}