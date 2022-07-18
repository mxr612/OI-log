/**
 * @file C.cpp
 * @author mxr612 (mxr612@icloud.com)
 * @date 2022-07-18
 * @brief 
 */

#include <stdio.h>
#include <algorithm>

int h[200010];
long long a[200010],c;

int nx(int a){return a>0?a:0;}

int main(){
#ifndef ONLINE_JUDGE
    freopen("C.in","r",stdin);
#endif

    int t,n;

    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",h+i);
        if(n&1){
            c=0;
            for(int i=2;i<n;i+=2)
                c+=nx(std::max(h[i-1],h[i+1])-h[i]+1);
        } else{
            for(int i=2;i<n;i+=2)
                a[i]=a[i-2]+nx(std::max(h[i-1],h[i+1])-h[i]+1);
            for(int i=n-1;i>1;i-=2)
                a[i]=a[i+2]+nx(std::max(h[i-1],h[i+1])-h[i]+1);
            c=std::min(a[3],a[n-2]);
            for(int i=3;i<=n-3;i+=2)
                c=std::min(c,a[i-1]+a[i+2]);
            for(int i=2;i<n;++i)
                a[i]=0;
        }
        printf("%lld\n",c);
    }

    return 0;
}