#include <stdio.h>

#define max(a,b) a>b?a:b

int v, n;
int wp[40];
int dp[20001] = {0};
int cmd;

int main(int argc, char const *argv[])
{
	freopen("P1049.in", "r", stdin);
	scanf("%d", &v);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &cmd);
		for (int j = v; j >= 0; j--) {
			if (j >= cmd) {
				dp[j]=max(dp[j-cmd]+cmd,dp[j]);
			}
		}
	}

	printf("%d", v - dp[v]);
	return 0;
}