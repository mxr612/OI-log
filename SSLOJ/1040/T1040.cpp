// 1040.in

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int m, n;


unsigned long long E[100][100];
bool ckE[100][100] = {false};

unsigned long long V[101];
queue<short>que;
short top;

int main() {
	freopen("T1040.in", "r", stdin);

	memset(V, 0x6f, sizeof(V));
	memset(E, 0x3f, sizeof(E));
	
	cin >> m >> n;
	for (int i = 1, x, y; i <= n; i++)
		cin >> x >> y >> E[x][y], ckE[x][y] = true;

	V[0] = 0;
	que.push(0);

	while (!que.empty()) {
		if(que.front()==m&&V[m]<V[101])
			break;
		top=que.front();
		que.pop();

		for(int i=1;i<=m;i++){
			if(ckE[top][i]){
				V[i]=min(V[i],V[top]+E[top][i]);
				que.push(i);
			}
		}
	}

	for(int i=0;i<=m;i++){
		cout<<' '<<V[i]<<endl;
	}

	// cout<<V[m];

	return 0;
}