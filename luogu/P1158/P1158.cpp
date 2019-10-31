// P1158.in

#include <iostream>
#include <algorithm>
using namespace std;

int N, x1, x2, y1, y2, x, y;

struct node {int a, b;} nodes[100001];
int cmpS(node m, node n) {return m.a < n.a;}

int maxb[100001] = {0};

int ans = 80000000;

int main() {
	freopen("P1158.in", "r", stdin);
	cin >> x1 >> y1 >> x2 >> y2 >> N;
	for (int i = 1; i <= N; i++)
		cin >> x >> y, nodes[i].a = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y), nodes[i].b = (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y);
	sort(&nodes[1], &nodes[N + 1], cmpS);
	for (int i = N; i > 0; i--)
		maxb[i] = max(nodes[i].b, maxb[i + 1]);
	nodes[0].a = 0;
	for (int i = 0; i <= N; i++)
		ans = min(ans, nodes[i].a + maxb[i + 1]);
	cout << ans;
	return 0;
}