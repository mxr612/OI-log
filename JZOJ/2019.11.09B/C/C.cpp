/**
 * 2019.11.09【NOIP提高组】模拟 A 组
 * C 字符串查询
 */

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

int n, q;
std::string s, a, b;
bool cheak[50020] = {false};

struct __mark {
	int x;
	__mark *nx = NULL;
}*pmark;
struct __trie {
	__mark *pt = NULL;
	__trie *nx[200] = {NULL};
} *L, *R, *ptrie;
void _left_in(std::string &s, int x) {
	ptrie = L;
	for (int i = 0; i < (int)s.size(); ++i) {
		pmark = NULL;
		while (pmark == NULL)pmark = (__mark *)calloc(1, sizeof(__mark));
		pmark->x = x, pmark->nx = ptrie->pt, ptrie->pt = pmark;
		while (ptrie->nx[(int)s[i]] == NULL)ptrie->nx[(int)s[i]] = (__trie *)calloc(1, sizeof(__trie));
		ptrie = ptrie->nx[(int)s[i]];
	}
}
void _right_in(std::string &s, int x) {
	ptrie = R;
	for (int i = (int)s.size() - 1; i >= 0 ; --i) {
		pmark = NULL;
		while (pmark == NULL)pmark = (__mark *)calloc(1, sizeof(__mark));
		pmark->x = x, pmark->nx = ptrie->pt, ptrie->pt = pmark;
		while (ptrie->nx[(int)s[i]] == NULL)ptrie->nx[(int)s[i]] = (__trie *)calloc(1, sizeof(__trie));
		ptrie = ptrie->nx[(int)s[i]];
	}
}
__mark *_left_get() {
	ptrie = L;
	for (int i = 0; i < (int)a.size(); ++i)
		ptrie = ptrie->nx[(int)a[i]];
	return ptrie->pt;
}
__mark *_right_get() {
	ptrie = R;
	for (int i = (int)b.size() - 1; i >= 0; --i)
		ptrie = ptrie->nx[(int)b[i]];
	return ptrie->pt;
}
int _cnt(__mark *x, __mark *y) {
	int res = 0;
	for (__mark *i = x; i != NULL; i = i->nx)cheak[i->x] = true;
	for (__mark *i = y; i != NULL; i = i->nx)if (cheak[i->x])++res;
	for (__mark *i = x; i != NULL; i = i->nx)cheak[i->x] = false;
	return res;
}
void _mark_free(__mark *&p) {if (p != NULL)_mark_free(p->nx), free(p), p = NULL;}
void _trie_free(__trie *&p) {if (p != NULL) {_mark_free(p->pt); for (int i = 0; i < 200; ++i)_trie_free(p->nx[i]);}}

int main() {
	freopen("C.in", "r", stdin);
	// freopen("C.out", "w", stdout);
	while (L == NULL)L = (__trie *)calloc(1, sizeof(__trie));
	while (R == NULL)R = (__trie *)calloc(1, sizeof(__trie));
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
		std::cin >> s, _left_in(s, i), _right_in(s, i);
	for (int i = 1; i <= q; ++i)
		std::cin >> a >> b, std::cout << _cnt(_left_get(), _right_get()) << std::endl;
	_trie_free(L), _trie_free(R);
	return 0;
}