// A

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int n, typ[1100], cop;
string coper, who[1100], what[1100];
map<string, int>mp;

int main() {

	freopen("A.in", "r", stdin);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> typ[i];
		if (typ[i] == 1) {
			cin >> who[i] >> what[i];
			if (what[i] == "thanks")
				mp[who[i - 1]] -= ((mp[who[i - 1]] == 0) ? (0) : (1));
			else if (i > 2 && who[i] == who[i - 1] && who[i] == who[i - 2] && what[i] == what[i - 1] && what[i] == what[i - 2])
				mp[who[i]]++;
		} else {
			cin >> cop;
			for (int j = 1; j <= cop; ++j)
				cin >> coper, mp[coper] -= ((mp[coper] == 0) ? (0) : (1));
		}
	}

	sort(&who[1], &who[n + 1]);

	for (int i = 1; i <= n; ++i) {
		if(who[i]!=who[i-1]&&mp[who[i]]>0)
			cout << who[i] << ' ' << mp[who[i]] << endl;
	}

	return 0;

}