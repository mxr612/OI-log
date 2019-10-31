#include <bits/stdc++.h>
using namespace std;

char A[101]={0}, B[101]={0}, C[101]={0};
char DY[129] = {0};
char BK[129] ={0};

int main(int argc, char const *argv[])
{
	freopen("testdata (1).in", "r", stdin);
	cin >> A;
	cin >> B;
	cin >> C;
	for(int i=0;A[i]!=0;i++){
		if(DY[(int)A[i]]!=B[i]||BK[(int)B[i]]!=A[i]){
			if(DY[(int)A[i]]==0&&BK[(int)B[i]]==0){
				DY[(int)A[i]]=B[i];
				BK[(int)B[i]]=A[i];
			}else{
				cout<<"Failed";
				return 0;
			}
		}
	}
	for(char i='A';i<='Z';i++){
		if(DY[(int)i]==0){
			cout<<"Failed";
			return 0;
		}
	}
	for(int i=0;C[i]!=0;i++){
		cout<<DY[(int)C[i]];
	}
	return 0;
}