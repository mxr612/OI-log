// U75702

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {int num; int fr, to; bool flag;} nums[100001];
struct cmpQ {bool operator()(int a, int b) {return nums[a].num < nums[b].num;}};
priority_queue<int, vector<int>, cmpQ>pq;
#define TOP (nums[pq.top()])
#define NEX (nums[(nums[pq.top()]).to])
int n;

int main() {

	freopen("U75702.in", "r", stdin);
	freopen("U75702.out", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> nums[i].num;
		nums[i].fr = i - 1; nums[i].to = i + 1;
		nums[i].flag = true;
		pq.push(i);
	}

	while (!pq.empty()) {
		if (TOP.flag && TOP.to <= n) {
			cout << TOP.num << ' ' << NEX.num << ' ';
			NEX.flag = false;
			nums[TOP.fr].to = NEX.to;
			nums[NEX.to].fr = TOP.fr;
		}
		pq.pop();
	}

	return 0;

}