#include <iostream>

using namespace std;

int n;
int zs[20000],pt=1;
int fg[200000]={0};

int main(){
	freopen("P1579.in","r",stdin);
	cin>>n;
	zs[1]=2;fg[2]=1;
	for(int i=3,sign;i<=20000;i++){
		sign=0;
		for(int j=1;j<=pt&&sign==0;j++)
			if(i%zs[j]==0)
				sign=1;
		if(sign==0){
			zs[++pt]=i;
			fg[i]=1;
		}
	}
	for(int i=1;i<pt;i++){
		for(int j=1,k;j<pt;j++){
			k=n-zs[i]-zs[j];
			if(fg[k]==1){
				cout<<zs[i]<<' '<<zs[j]<<' '<<k<<endl;
				return 0;
			}
		}
	}
	return 0;
}