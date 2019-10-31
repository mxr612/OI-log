// P3956.in

#include <iostream>
#include <cstring>
using namespace std;

int m,n;

int MapOf[101][101];

int main(){
	freopen("P3956.in","r",stdin);

	memset(MapOf,-1,sizeof(MapOf));

	cin>>m>>n;
	for(int i=1,x,y;i<=n;i++)
		cin>>x>>y>>MapOf[x][y];

	return 0;
}