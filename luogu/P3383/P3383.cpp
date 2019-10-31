// P3383 【模板】线性筛素数

#include <stdio.h>
#include <iostream>

int  N, M;

int prime[10000000], pt = 1;
bool flag[10000000] = {false};

int main() {

	freopen("P3383.in", "r", stdin);

	std::cin >> N >> M;

	flag[1] = true;
	for (int i = 2; i <= N; ++i) {
		if (!flag[i])
			prime[++pt] = i;
		for (int j = 1; j <= pt && prime[j]*i <= N; ++j)
			flag[prime[j]*i] = true;
	}

	for (int i = 1, cmp; i <= M; ++i)
		std::cin >> cmp, std::cout << (flag[cmp] ? "No" : "Yes") << std::endl;

	return 0;
}