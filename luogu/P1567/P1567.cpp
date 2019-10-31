#include <iostream>

using namespace std;

int N;
int ans=0,acmp=0;
int cmp1,cmp2;

int main(){
	freopen("P1567.in","r",stdin);
	cin>>N>>cmp1;
	for(int i=1;i<N;i++){
		cin>>cmp2;
		if(cmp1<cmp2){
			acmp++;
		}else{
			acmp++;
			ans=acmp>ans?acmp:ans;
			acmp=0;
		}
		cmp1=cmp2;
	}
	cout<<ans;
	return 0;
}