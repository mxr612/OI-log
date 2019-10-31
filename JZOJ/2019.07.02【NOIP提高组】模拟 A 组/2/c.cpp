#include<bits/stdc++.h>
using namespace std;
const int mo=30011;int n,m;
struct M{
    int w[105][105];
    M(){memset(w,0,sizeof(w));}
    int *operator[](int a){return w[a];}
    M operator*(M &a){
        M c;for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) for(int k=1;k<=n;++k)
        c[i][j]=(c[i][j]+w[i][k]*a[k][j])%mo;return c;
    }
}p,x,y;
M pow(M a,int b){
    M c;for(int i=1;i<=n;++i) c[i][i]=1;
    for(;b;b>>=1,a=a*a) if(b&1) c=c*a;return c;
}
int main(){
    freopen("2.in","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) p[i][i]=p[i+n][i]=p[i][i+n]=1;
    for(int i=1;i<n;++i) p[i+1][i]=p[i][i+1]=1;n<<=1,x=pow(p,m-2),y=x*p;
    return !printf("%d",(y[1][n>>1]-x[1][n]+mo)%mo);
}