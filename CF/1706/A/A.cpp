/**
 * @file A.cpp
 * @author mxr612 (mxr612@icloud.com)
 * @date 2022-07-18
 * @brief 
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>

bool s[100];

int main(){
#ifndef ONLINE_JUDGE
    freopen("A.in","r",stdin);
#endif

    int t,n,m,a;

    scanf("%d",&t);

    while(t--){
        memset(s,0,sizeof(s));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i){
            scanf("%d",&a);
            if(s[std::min(a,m+1-a)])
                s[std::max(a,m+1-a)]=1;
            else 
                s[std::min(a,m+1-a)]=1;
        }
        for(int i=1;i<=m;++i)
            printf("%c",s[i]?'A':'B');
            putchar('\n');
    }

    return 0;
}