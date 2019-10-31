// P1115

#include <iostream>
using namespace std;

int N,cmp,sum=0,ans=-100000;

int main(){
	freopen("P1115.in","r",stdin);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>cmp;
		ans=max(ans,cmp);
		sum+=cmp;
		if(sum<0)
			sum=0;
		else
			ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}