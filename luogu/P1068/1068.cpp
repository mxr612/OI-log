#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

#define MAX_N 5000

struct man
{
	int ID;
	int s;
} mans[MAX_N + 2];

int n, m,mu=0;

int qcmps(const void *a, const void *b) {
	return (*(struct man *)b).s - (*(struct man *)a).s;
}

int qcmpID(const void *a, const void *b) {
	return (*(struct man *)a).ID - (*(struct man *)b).ID;
}

int main()
{
	freopen("testdata.in", "r", stdin);
	cin>>n>>m;
	m = floor(m * 1.5);
	for (int i = 1; i <= n; i++) {
		cin >> mans[i].ID;
		cin >> mans[i].s;
	}
	qsort(&mans[1], n, sizeof(mans[0]), qcmps);
	for(int i=1;mans[i].s>=mans[m].s;i++){
		int cmp=i;
		while(mans[i].s==mans[cmp].s)i++;
		i--;
		qsort(&mans[cmp],i-cmp+1,sizeof(mans[0]),qcmpID);
		mu=i;
	}
	printf("%d %d\n", mans[m].s, mu);
	for (int i = 1; i<=mu; i++) {
		printf("%d %d\n", mans[i].ID, mans[i].s);
	}
	return 0;
}