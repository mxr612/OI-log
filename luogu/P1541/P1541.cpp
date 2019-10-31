// P1541

#include <iostream>
using namespace std;

int N,M;
int a[400],b[5]={0};
int DP[50][50][50][50]={0};

int main(){
	freopen("P1541.in","r",stdin);
	cin>>N>>M;
	for(int i=1;i<=N;i++)
		cin>>a[i];
	for(int i=1,cmp;i<=M;i++){
		cin>>cmp;
		b[cmp]++;
	}
	DP[0][0][0][0]=a[1];
	for(int i=0;i<=b[1];i++){
		for(int j=0;j<=b[2];j++){
			for(int k=0;k<=b[3];k++){
				for(int l=0;l<=b[4];l++){
					if(i>0)
						DP[i][j][k][l]=max(DP[i][j][k][l],DP[i-1][j][k][l]+a[1+i+2*j+3*k+4*l]);
					if(j>0)
						DP[i][j][k][l]=max(DP[i][j][k][l],DP[i][j-1][k][l]+a[1+i+2*j+3*k+4*l]);
					if(k>0)
						DP[i][j][k][l]=max(DP[i][j][k][l],DP[i][j][k-1][l]+a[1+i+2*j+3*k+4*l]);
					if(l>0)
						DP[i][j][k][l]=max(DP[i][j][k][l],DP[i][j][k][l-1]+a[1+i+2*j+3*k+4*l]);
				}
			}
		}
	}
	cout<<DP[b[1]][b[2]][b[3]][b[4]];
	return 0;
}