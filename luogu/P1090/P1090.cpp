/**
 * heap
 */

#include <stdio.h>
#include <vector>

class __heap {

	int arr[10020], size = 0;

	void _swap(register int &x, register int &y) {
		register int cmp = x;
		x = y;
		y = cmp;
	}

	void _up(register int v) {
		while (v > 1 && arr[v]<arr[v >> 1])
			_swap(arr[v], arr[v >> 1]), _down(v), v >>= 1;
	}

	void _down(register int v) {
		if (v > size)return ;
		if (v << 1 <= size && arr[v << 1] < arr[v])_swap(arr[v << 1], arr[v]);
		if ((v << 1) + 1 <= size && arr[(v << 1) + 1] < arr[v])_swap(arr[(v << 1) + 1], arr[v]);
		_down(v << 1), _down((v << 1) + 1);
	}

public:

	inline void _push(register int x) {
		arr[++size] = x;
		_up(size);
	}

	inline void _pop() {
		arr[1] = arr[size--];
		_down(1);
	}

	inline int _top() {
		return arr[1];
	}

} heap;

int main() {

	freopen("P1090.in", "r", stdin);

	int n, x;
	register int ans = 0;

	scanf("%d", &n);

	for (register int i = 0; i < n; ++i)
		scanf("%d", &x), heap._push(x);
	// for (int i = 0; i <= n; ++i, heap._pop())
	// 	printf("%d ", heap._top());

	for (register int i = 1, a, b; i < n; ++i) {
		a = heap._top(), heap._pop();
		b = heap._top(), heap._pop();
		ans += a + b;
		heap._push(a + b);
	}

	printf("%d\n", ans);

	return 0;
}