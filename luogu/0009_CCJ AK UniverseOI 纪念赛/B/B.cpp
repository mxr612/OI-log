// B

#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	int A, B,id;
} C[100001];

int Qcmp(node m, node n) {
	if (m.B == n.B)
		return m.A < n.A;
	return m.B > n.B;
}

int n;

int DP[100001] = {0};
int fr[100001] = {0};

int ans=0;

void print(int pt){
	if(pt==0)
		return ;
	print(fr[pt]);
	cout<<C[pt].id<<' ';
}

int main() {
	freopen("B.in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> C[i].A;
	for (int i = 1; i <= n; i++)
		cin >> C[i].B;
	for(int i=1;i<=n;i++)
		C[i].id=i;

	sort(&C[1], &C[n + 1], Qcmp);

	for(int i=1;i<=n;i++){
		DP[i]=1;
		for(int j=1;j<i;j++){
			if(C[j].A<=C[i].A&&DP[j]+1>DP[i]){
				DP[i]=DP[j]+1;
				fr[i]=j;
			}
		}
	}

	for(int i=1;i<=n;i++)
		if(DP[ans]<DP[i])
			ans=i;
	cout<<ans<<endl;
	print(ans);

	return 0;
}