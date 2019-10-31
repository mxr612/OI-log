// C 【NOIP2013模拟】开心小屋

#include <stdlib.h>

#include <iostream>
using namespace std;
struct __edge {
	int u, v;
	__edge *_in = NULL, *in_ = NULL, *_out = NULL, *out_ = NULL;
} out[500], in[500], *p;
int n, m;
int main() {
	freopen("C.in", "w", stdin);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		p = (__edge *)calloc(1, sizeof(__edge));
		cin >> p->u >> p->v;
		p->out_ = out[p->u].out_, p->_out = NULL, out[p->u].out_->_out = p, out[p->u].out_ = p;
		p->in_ = in[p->v].in_, p->_in = NULL, in[p->v].in_->_in = p, in[p->v].in_ = p;
	}

	return 0;
}