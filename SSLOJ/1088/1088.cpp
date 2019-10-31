//1088
#include <iostream>
#include <cstdio>
using namespace std;

int M,N;
int In_Put[101][101]={0},cha_zhi[101][101][4], ans=-1;
int dp[101][101][2];


/**
 * M行N列
 * In_Put输入矩阵
 * 
 */

void dfs(int i,int j,int cha){
	
}

int main(int argc, char const *argv[])
{
	/**
	 * 输入
	 */
	freopen("1088.in","r",stdin);
	cin>>M>>N;
	for (int i = 1; i <= M; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin>>In_Put
		[i][j];
		}
	}
	/**
	 * 计算每个点四周差值
	 */
	for (int i = 1; i <= M; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cha_zhi[i][j][0]=In_Put[i][j]-In_Put[i][j+1];
			cha_zhi[i][j][1]=In_Put[i][j]-In_Put[i+1][j];
			cha_zhi[i][j][2]=In_Put[i][j]-In_Put[i][j-1];
			cha_zhi[i][j][3]=In_Put[i][j]-In_Put[i-1][j];
		}
	}
	for (int i = 1; i <= M; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			dfs(i,j,cha_zhi[0]);
			dfs(i,j,cha_zhi[1]);
			dfs(i,j,cha_zhi[2]);
			dfs(i,j,cha_zhi[3]);
		}
	}
	return 0;
}
