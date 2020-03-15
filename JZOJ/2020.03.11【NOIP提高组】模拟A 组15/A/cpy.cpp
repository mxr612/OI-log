#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <string.h>

using namespace std;

namespace inout
{
const int S = 1 << 20;
char frd[S], *ihed = frd + S;
const char *ital = ihed;

inline char inChar()
{
	if (ihed == ital)
		fread(frd, 1, S, stdin), ihed = frd;
	return *ihed++;
}

inline int get()
{
	char ch; int res = 0; bool flag = false;
	while (!isdigit(ch = inChar()) && ch != '-');
	(ch == '-' ? flag = true : res = ch ^ 48);
	while (isdigit(ch = inChar()))
		res = res * 10 + ch - 48;
	return flag ? -res : res;
}

char fwt[S], *ohed = fwt;
const char *otal = ohed + S;

inline void outChar(char ch)
{
	if (ohed == otal)
		fwrite(fwt, 1, S, stdout), ohed = fwt;
	*ohed++ = ch;
}

inline void put(int x)
{
	if (x > 9) put(x / 10);
	outChar(x % 10 + 48);
}
};
using namespace inout;

#define N (100020)


struct Heap
{
	int g[N], len;

	inline void Push(register int res)
	{
		int now = ++len, nxt = len >> 1;
		while (nxt)
		{
			if (res < g[nxt])
				g[now] = g[nxt], now = nxt, nxt >>= 1;
			else break;
		}
		g[now] = res;
	}

	inline void Pop()
	{
		int now = 1, nxt = 2, res = g[len--];
		while (nxt <= len)
		{
			if (nxt < len && g[nxt | 1] < g[nxt]) nxt |= 1;
			if (g[nxt] < res)
				g[now] = g[nxt], now = nxt, nxt <<= 1;
			else break;
		}
		g[now] = res;
	}
} Q;

signed main()
{
	register int m, k;
	m = get(); Q.len = 0;
	while (m--)
	{
		k = get();
		switch (k)
		{
		case 1: Q.Push(get()); break;
		case 2: put(Q.g[1]), outChar('\n'); break;
		case 3: Q.Pop(); break;
		}
	}
	fwrite(fwt, 1, ohed - fwt, stdout);
	return 0;
}