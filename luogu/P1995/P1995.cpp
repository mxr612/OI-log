#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int N,j,max_ans=-1,min_ans=0x6f;
int NumOfStone[101],max_DP[101][101]={0},min_DP[101][101],Sum[201]={0};

int main(int argc, char const *argv[])
{
	freopen("P1995.in","r",stdin);
	memset(min_DP,0x3f,sizeof(min_DP));
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>NumOfStone[i];
		Sum[i]=Sum[i-1]+NumOfStone[i];
		min_DP[i][i]=0;
	}
	for(int i=1;i<=N;i++){
		Sum[i+N]=Sum[i]+Sum[N];
	}
	//
	for(int l=2;l<=N;l++){
		for(int i=1;i<=N;i++){
			j=i+N-1;
			for(int k=i;k<j;k++){
				max_DP[i][j]=max(max_DP[i][j],max_DP[i][k]+max_DP[k+1][j]+Sum[j]-Sum[i-1]);
				min_DP[i][j]=min(min_DP[i][j],min_DP[i][k]+min_DP[k+1][j]+Sum[j]-Sum[i-1]);
			}
		}
	}
	for(int i=1;i<=2*N;i++){
		for(int j=1;j<=2*N;j++){
			printf("%12d",max_DP[i][j]);
		}
		putchar('\n');
	}
	for(int i=1;i<=N;i++){
		min_ans=min(min_ans,min_DP[i][i+N-1]);
		max_ans=min(max_ans,max_DP[i][i+N-1]);
	}
	cout<<min_ans<<endl<<max_ans;
	return 0;
}
