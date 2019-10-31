#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int num[200000];

int main(){
	freopen("P1177.in","r",stdin);
	freopen("P1177.out","w",stdout);
	scanf("%d",&N);
	for(int i=0;i<=N;i++)
		scanf("%d",&num[i]);
	sort(num,num+N);
	for(int i=0;i<N;i++)
		printf("%d ",num[i]);
	return 0;
}