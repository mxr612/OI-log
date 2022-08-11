/**
 * @file A.cpp
 * @author mxr612 (mxr612@icloud.com)
 * @date 2022-07-31
 * @brief 
 */

#include <stdio.h>

char a[100],b[100];

int main(){
#ifndef ONLINE_JUDGE
    freopen("A.in","r",stdin);
#endif

    int t,n,m,i,j;

    scanf("%d",&t);

    while(t--){
        scanf("%d%d",&n,&m);
        scanf("%s",a+1);
        scanf("%s",b+1);
        for(i=n,j=m;i>0&&j>0&&a[i]==b[j];)--i,--j;
        if(j==0){
            printf("YES\n");
        }else if(j==1){
            for(;i>0;--i){
                if(a[i]==b[j]){
                    printf("YES\n");
                    break;
                }
            }
            if(i==0)
                printf("NO\n");
        }else{
            printf("NO\n");   
        }
    }

    return 0;
}