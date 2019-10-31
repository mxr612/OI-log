#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int E[300];

int A;

int main() {
	freopen("pq.in", "r", stdin);
	cin >>A;
	for (int i = 1; i <= A; i++)
		cin >> E[i];
	priority_queue<int> pq;
	for(int i=1;i<=A;i++)
		pq.push(i);
	E[1]=10;
	cout<<pq.top();
	return 0;
}