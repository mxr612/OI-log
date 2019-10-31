#include <bits/stdc++.h>
using namespace std;

int n,k[200],b[200],pt=0,ans=0;
double x[40000],y[40000];

int main(int argc, char const *argv[])
{
	freopen("80.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k[i]>>b[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(!(k[i]==k[j]&&b[i]!=b[j])){
				pt++;
				x[pt]=(double)(b[j]-b[i])/(k[i]-k[j]);
				y[pt]=(double)k[i]*x[pt]+b[i];
			}
		}
	}
	for(int i=1;i<=pt;i++){
		int ck=0;
		for(int j=1;j<i;j++){
			if(x[i]==x[j]&&y[i]==y[j]){
				ck=1;
				break;
			}
		}
		if(ck==0){
			ans++;
		}
	}
	if(ans==0){
		cout<<"No Fire Point.";
	}else{
		cout<<ans;
	}
	return 0;
}