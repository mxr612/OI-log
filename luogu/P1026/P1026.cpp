// P1026

#include <iostream>
#include <string>
using namespace std;

int p, k, s;
string str = " ", cmp;

int bt[250][250]={0},DP[250];

int main() {
	freopen("P1026.in", "r", stdin);
	cin >> p >> k;
	for (int i = 1; i <= p; i++) {
		cin >> cmp;
		str.append(cmp);
	}
	p *= 20;
	cin >> s;
	for(int i=1;i<=s;i++){
		cin>>cmp;
		for(int j=str.find(cmp,1);0<j&&j<=p;j=str.find(cmp,j+1)){
			for(int k=j+cmp.size()-1;k<=p;k++){
				bt[j][k]++;
			}
		}
	}
	for(int i=1;i<=p;i++){
		DP[i]=bt[1][i];
	}
	for(int f=2;f<=k;f++){
		for(int i=p;i>=f;i--){
			DP[i]=0;
			for(int j=f-1;j<i;j++){
				DP[i]=max(DP[i],DP[j]+bt[j+1][i]);
			}
		}
	}
	cout<<DP[p];
	return 0;
}