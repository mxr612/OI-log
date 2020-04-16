// 0

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int n,h;
int a[100001]={0};

#define G(y,z) (a[(y-1)*h+z])

double l=1e9,r=-1,m;
double s,c;

double cmp[100001];

int main(){

	freopen("0.in","r",stdin);

	cin>>n>>h;

	for(int i=1;i<=n;++i){
		for(int j=1;j<=h;++j){
			cin>>G(i,j);
			l=min((int)l,G(i,j));
			r=max((int)r,G(i,j));
			G(i,j)+=(j==1)?(0):G(i,j-1);
		}
	}

	while(r-l>1e-6){
		m=(l+r)/2;
		s=0;
		for(int i=1;i<=n;++i){
			c=-1e9;
			for(int j=1;j<=h;++j)
				c=max(c,m*j-G(i,j));
			s+=c;
		}
		if(s>0) r=m;
		else l=m;
	}

	printf("%.4f\n", r);


	return 0;
}