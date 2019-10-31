// P1341

#include <iostream>

using namespace std;

const int ASC = 150;

int n;
bool G_E[ASC][ASC] = {false}, G_V[ASC] = {false};
int due[ASC] = {0};
int sta = -1, stj = -1, ji = 0;
bool V_ask[ASC] = {false};
int cnt_ask = 0,cnt_V=0;

char str[3000] = {0};

void _dfs_ck(int node);
void _dfs_pt(int node);

int main() {
// InPut
	freopen("testdata.in", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b;
		cin >> a >> b;
		G_V[int(a)] = G_V[int(b)] = true;
		G_E[int(a)][int(b)] = G_E[int(b)][int(a)] = true;
		due[int(a)]++; due[int(b)]++;
	}
// Preprocess
	str[n + 1] = '\0';
	for (int i = ASC; i > 0; i--)if (G_V[i]) {
		cnt_V++;
			sta = i;
			if (due[i] % 2 == 1) {
				stj = i;
				ji++;
			}
		}
	_dfs_ck(sta);
	for (int i = 1; i < ASC; i++)cnt_ask += V_ask[i];
// H
	if (cnt_ask == cnt_V && (ji == 0 || ji == 2)) {
		if (ji == 0)
			_dfs_pt(sta);//欧拉回路
		else
			_dfs_pt(stj);//欧拉路
		cout<<str;
	} else {
		cout << "No Solution";
	}
	return 0;
}

void _dfs_ck(int node) {

	V_ask[node] = true;
	for (int i = 1; i < ASC; i++)if (G_E[node][i] && !V_ask[i])
			_dfs_ck(i);
}

void _dfs_pt(int node) {
	for(int i=1;i<ASC;i++)if(G_E[node][i]){
		G_E[node][i]=G_E[i][node]=false;
		_dfs_pt(i);
	}
	str[n--]=node;
}