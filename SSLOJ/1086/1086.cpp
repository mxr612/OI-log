#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double r,ans=-1,ans_a=-1,ans_b=-1,S;

int main()
{
	freopen("1086.in","r",stdin);
	cin>>r;
	for(int a=1;a<=sqrt(2)*r;a++){
		for(int b=1;b<=sqrt(2)*r;b++){
			S=a*sqrt(4*r*r-a*a)+b*sqrt(4*r*r-b*b)-a*b;
			if(ans<S){
				ans_a=a;
				ans_b=b;
				ans=S;
				// cout<<ans<<" ";
			}
		}
	}
	cout<<ans_a<<endl<<ans_b;
}
