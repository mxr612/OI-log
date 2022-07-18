/**
 * @file B.cpp
 * @author mxr612 (mxr612@icloud.com)
 * @date 2022-07-18
 * @brief 
 */

#include <stdio.h>
#include <algorithm>

int last[100010][2];

int main(){
#ifndef ONLINE_JUDGE
    freopen("B.in","r",stdin);
#endif

    int t,n,c;

    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d",&c);
            if(i&1)
                last[c][1]=std::max(last[c][1],last[c][0]+1);
            else
                last[c][0]=std::max(last[c][0],last[c][1]+1);
        }
        for(int i=1;i<=n;++i){
                printf("%d ",std::max(last[i][0],last[i][1]));
            last[i][0]=last[i][1]=0;
        }
        putchar('\n');
    }

    return 0;
}