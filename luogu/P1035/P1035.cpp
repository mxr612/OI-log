/**
 * P1035
 * 级数求和
 */

#include <iostream>
using namespace std;

int K;
double i = 1;
double sum = 0;

int main(int argc, char const *argv[])
{
	// freopen("P1035.in", "r", stdin);
	cin >> K;
	for (; sum <= K; i++) {
		sum +=  1 / i;
	}
	cout << i-1;
	return 0;
}