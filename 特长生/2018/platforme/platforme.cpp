// platforme.in

#include <iostream>
#include <cstdio> 
#include <algorithm>
using namespace std;

int N;

struct node {int y, x1, x2;} nodes[101];
int _Cmp(node m, node n) {return m.y < n.y;}

int top[10001] = {0};

int ans = 0;

int main() {
	freopen("platforme.in", "r", stdin);
	freopen("platforme.out","w",stdout);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> nodes[i].y >> nodes[i].x1 >> nodes[i].x2;

	sort(&nodes[0], &nodes[N + 1], _Cmp);

	for (int i = 1; i <= N; i++) {
		ans += 2 * nodes[i].y - top[nodes[i].x1] - top[nodes[i].x2 - 1];
		for (int j = nodes[i].x1; j <= nodes[i].x2; j++)
			top[j] = nodes[i].y;
	}

	cout<<ans;

	return 0;
}
