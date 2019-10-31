// P1019.in
// testdata.in

#include <iostream>
#include <string>
using namespace std;

int n;
char Key;
string Words[30];

#define _Low(m) ((m)<1?1:(m))
int _Same(string a, string b);
int Edge[30][30] = {0};

int Vis[30] = {0};
void _dfs(int Dad, int Len);

int ans = 0;

int main() {
	freopen("P1019.in", "r", stdin);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> Words[i];
	cin >> Key;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			Edge[i][j] = _Same(Words[i], Words[j]);

	for (int i = 1; i <= n; i++) {
		if (Words[i][0] == Key) {
			Vis[i]++;
			_dfs(i, Words[i].size());
			Vis[i]--;
		}
	}

	cout << ans;

	return 0;
}

int _Same(string a, string b) {
	int LenA = a.size(), LenB = b.size(),ans=0;
	string CmpA, CmpB;
	for (int i = _Low(LenA - min(LenA, LenB)); i < LenA; i++) {
		CmpA.assign(a, i, LenA);
		CmpB.assign(b, 0, LenA - i);
		if(CmpA==CmpB)
			ans=LenA - i;
	}
	return ans;
}

void _dfs(int Dad, int Len) {
	ans = max(ans, Len);
	for (int i = 1; i <= n; i++) {
		if (Edge[Dad][i] > 0 && Vis[i] < 2) {
			Vis[i]++;
			_dfs(i, Len + Words[i].size() - Edge[Dad][i]);
			Vis[i]--;
		}
	}
}
