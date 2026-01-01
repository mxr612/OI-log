#include<iostream>

using namespace std;

int countY(string s){
	short count = 0;
	for(int i=0;i< s.size();++i)
		count += s[i] == 'Y';
	return count;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("A.in", "r", stdin);
	#endif

	int tests;
	string s;

	cin >> tests;

	while(tests--){
		cin >> s;
		cout << (countY(s) <= 1 ? "YES" : "NO") << endl;
	}

	return 0;
}