// P1330

#include <iostream>
#include <cstring>

using namespace std;

const int MaxN = 10010, MaxM = 100010;

int N, M;
bool e[MaxN][MaxN] = {false};
short v[MaxN];
int ans = 0;

int m[2];

bool _2G(int s, int c);

int main() {
// Input
	freopen("testdata.in", "r", stdin);
	cin >> N >> M;
	for (int i = 1, a, b; i <= M; i++) {
		cin >> a >> b;
		e[a][b] = e[b][a] = true;
	}
// Reset
	memset(v,-1,sizeof(v));
// Mark
	for (int i = 1; i <= N; i++) {
		if (v[i] == -1) {
			m[0] = m[1] = 0;
			if (_2G(i, 0)) {
				ans += min(m[0], m[1]);
			} else {
				cout<<"Impossible";
				return 0;
			}
		}

	}
// Output
		cout << ans;
	return 0;
}

bool _2G(int s, int c) {
	v[s]=c;
	m[c]++;
	for(int i=1;i<=N;i++)
		if(e[s][i]){
			if(v[i]==c)
				return false;
			if(v[i]!=-1)
				continue;
			if(!_2G(i,c==0?1:0))
				return false;
		}
	return true;
}