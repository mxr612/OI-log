/**
 * P3378
 * heap
 */

#include <stdio.h>

class __heap {
	int arr[1000020], size = 0;

	inline void _swap(int &a, int &b) {
		register int g = a;
		a = b;
		b = g;
	}

	void _down(int v) {
		if (v << 1 <= size && arr[v << 1] < arr[v])
			_swap(arr[v << 1], arr[v]), _down(v << 1);
		if (v << 1 < size && arr[(v << 1) + 1] < arr[v])
			_swap(arr[(v << 1) + 1], arr[v]), _down((v << 1) + 1);
	}

	void _up(register int v) {
		while (v > 1 && arr[v]<arr[v >> 1])
			_swap(arr[v], arr[v >> 1]), _down(v), v >>= 1;
	}

public:

	inline void _push(register int x) {
		arr[++size] = x;
		_up(size);
	}

	inline void _pop() {
		if (size > 0) {
			arr[1] = arr[size--];
			_down(1);
		}
	}

	inline int _top() {
		return arr[1];
	}

} heap;

signed main() {

	freopen("P3378.in", "r", stdin);

	int N, o, x;

	scanf("%d", &N);

	for (register int i = 0; i < N; ++i) {
		scanf("%d", &o);
		switch (o) {
		case 1:
			scanf("%d", &x);
			heap._push(x);
			break;
		case 2:
			printf("%d\n", heap._top());
			break;
		case 3:
			heap._pop();
			break;
		default:;
		}
	}

	return 0;

}