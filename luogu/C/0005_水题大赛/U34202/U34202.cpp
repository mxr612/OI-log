//U34202
#include <iostream>
#include <cstdio>
using namespace std;

int A,B,j,ans=0;

int main(int argc, char const *argv[])
{
	freopen("U34202.in","r",stdin);
	cin>>A>>B;
	j=1;
	while(j<=A)
	{
		ans*=2;
		if(j%2){
			ans+=A/j*-1;
		}else{
			ans+=A/j;
		}
		j++;
	}
	for(int i=A+1;i<=B;i++){
		ans*=2;
		if(j%2){
			ans+=i/j*-1;
		}else{
			ans+=i/j;
		}
	}
	printf("%d",ans);
	return 0;
}
