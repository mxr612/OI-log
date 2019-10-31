#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string key, sen, cmp;
int l=-1,r;
int count = 0, first = -1;

int main() {
	freopen("testdata.in", "r", stdin);
	cin >> key; getchar();
	getline(cin, sen);
	for (int i = 0; i < (int)key.size(); i++)
		if (key[i] >= 'A' && key[i] <= 'Z')
			key[i] += 32;
	for (int i = 0; i < (int)sen.size(); i++)
		if (sen[i] >= 'A' && sen[i] <= 'Z')
			sen[i] += 32;
	while(1==1){
		r=sen.find(' ',l+1);
		if(sen[r]!=' ')break;
		cmp.assign(sen,l+1,r-l-1);
		if(cmp==key){
			count++;
			if(first==-1)first=l+1;
			// cout<<l<<' '<<r<<endl;
		}
		l=r;
	}
	if (first == -1) {
		cout << -1;
	} else {
		cout << count << ' ' << first;
	}
	return 0;
}