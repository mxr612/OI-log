/**
 * P3369
 * 【模板】普通平衡树
 * 二叉查找树
 */

#include <stdio.h>

#define _SIZ(PTR) (((PTR)==NULL)?(0):((PTR)->siz))

struct __node {
	int val, cnt, siz;
	__node *ls, *rs;
} stack[100020], *root = NULL;
int usage = 0;

inline void _insert(register int a, register __node *&b) {
	if (b == NULL) b = &stack[++usage], b->val = a, b->cnt = b->siz = 1, b->ls = b->rs = NULL;
	else if (a < b->val) _insert(a, b->ls), ++b->siz;
	else if (a > b->val) _insert(a, b->rs), ++b->siz;
	else ++b->cnt, ++b->siz;
}
inline void _delete_(register __node *&b, register __node *p) {
	if (b->ls == NULL)p->val = b->val, p->cnt = b->cnt, b = b->rs;
	else _delete_(b->ls, p), b->siz = _SIZ(b->ls) + b->cnt + _SIZ(b->rs);
}
inline void _delete(register int a, register __node *&b) {
	if (a < b->val) _delete(a, b->ls), --b->siz;
	else if (a > b->val)_delete(a, b->rs), --b->siz;
	else if (b->cnt > 1) --b->cnt, --b->siz;
	else if (b->ls == b->rs) b = NULL;
	else if (b->ls == NULL) b = b->rs;
	else if (b->rs == NULL) b = b->ls;
	else _delete_(b->rs, b), --b->siz;
}
inline int _query_name(register int a, register __node *b, register int c) {
	if (b == NULL)return c + 1;
	else if (a < b->val)return _query_name(a, b->ls, c);
	else if (a > b->val) return _query_name(a, b->rs, c + _SIZ(b->ls) + b->cnt);
	else return c + _SIZ(b->ls) + 1;
}
inline int _query_rank(register int a, register __node *b) {
	if (a <= _SIZ(b->ls))return _query_rank(a, b->ls);
	else if (a <= _SIZ(b->ls) + b->cnt)return b->val;
	else return _query_rank(a - _SIZ(b->ls) - b->cnt, b->rs);
}
inline int _query_pre(register int a, register __node *b, register int c) {
	if (b == NULL || a == b->val)return c;
	else if (a < b->val)return _query_pre(a, b->ls, c);
	else return _query_pre(a, b->rs, b->val);
}
inline int _query_nxt(register int a, register __node *b, register int c) {
	if (b == NULL || a == b->val)return c;
	else if (a < b->val)return _query_nxt(a, b->ls, b->val);
	else return _query_nxt(a, b->rs, c);
}

inline void _print(register __node *b, register int c) {
	if (b == NULL)return ;
	_print(b->ls, c + 1);
	for (register int i = 0; i < c; ++i)putchar(' ');
	printf("%5d%5d%5d%5d%5d\n", b->val, _SIZ(b->ls), b->cnt, _SIZ(b->rs), _query_name(b->val, root, 0));
	_print(b->rs, c + 1);
}

int main() {

	freopen("P3369_4.in", "r", stdin);
	// freopen("P3369.out", "w", stdout);

	register int n, x, y;

	scanf("%d", &n);

	for (register int i = 0; i < n; ++i) {
		scanf("%d%d", &x, &y);
		switch (x) {
		case 1: _insert(y, root); break;
		case 2: _delete(y, root); break;
		case 3: printf("%d\n", _query_name(y, root, 0)); break;
		case 4: printf("%d\n", _query_rank(y, root)); break;
		case 5: printf("%d\n", _query_pre(y, root, 0)); break;
		case 6: printf("%d\n", _query_nxt(y, root, 0)); break;
		default:;
		}
	}

	// _print(root, 0);

	return 0;
}