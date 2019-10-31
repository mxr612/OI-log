#include<stdio.h>

int s,n,ans,a,b,t;

int main(){
    freopen("china.in","r",stdin);
    freopen("china.out","w",stdout);
   scanf("%d %d",&s,&n);
   ans=s;
   for(int i=0;i<n;i++) {
       scanf("%d %d %d",&a,&b,&t);
       ans+=(b-a+1)*(t-1);
   }
   printf("%d",ans);
   return 0;
}
