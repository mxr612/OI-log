// Span

#include <stdio.h>
#include <iostream>
#include <algorithm>

#define MAX_INT 300000

int T, N, M, res, ans = MAX_INT, V[110];

struct edge {
	int fr, to, vl;
} E[11000];

int _cmpS(edge m, edge n) {
	return m.vl < n.vl;
}
int _get(int id) {
	if (V[id] != id)
		V[id] = _get(id);
	return V[id];
}
void _merge(int a, int b) {
	a = _get(V[a]);
	b = _get(V[b]);
	V[a] = b;
}
int _sovle(int pt) {
	int  ds = E[pt].vl, cnt = N - 1;
	for (int i = 1; i <= N; ++i)
		V[i] = i;
	while (pt <= M) {
		if (--cnt) {
			_merge(E[pt].fr, E[pt].to);
			++pt;
			if(_get(E[pt].fr) == _get(E[pt].to))
				std::cout<<1;
			// while (pt <= M && _get(E[pt].fr) == _get(E[pt].to))
			// 	++pt;
		} else
			return E[pt].vl - ds;
	}
	return MAX_INT;
}

int main() {

	freopen("Span1.in", "r", stdin);

	std::cin >> T;

	for (int t = 0; t < T; ++t) {
		ans = E[0].vl = MAX_INT;
		std::cin >> N >> M;
		for (int i = 1; i <= M; ++i)
			std::cin >> E[i].fr >> E[i].to >> E[i].vl;
		std::sort(&E[1], &E[M + 1], _cmpS);
		for (int i = 1; i  <= M; ++i) {
			if (E[i].vl != E[i - 1].vl)
				std::cout << _sovle(i) << std::endl;
			// 	ans = std::min(ans, _sovle(i));
			// std::cout << E[i-1].vl << ' ' << E[i].vl << std::endl;
		}
		std::cout << std::endl;
		// std::cout << ((ans == MAX_INT) ? (-1) : (ans)) << std::endl;
	}

	return 0;
}