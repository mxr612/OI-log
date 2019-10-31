#include <stdio.h>

int N;
int num[1000000]={0};
int count=0;

void sort(int L,int R){
    if(L>=R)
        return ;
    int key=num[L];
    int l=L,r=R;
    while(l<r){
        while(l<r&&num[r]>=key)r--;
        if(l<r)
            num[l++]=num[r];
        while(l<r&&num[l]<key)l++;
        if(l<r)
            num[r--]=num[l];
    }
    num[r]=key;
    sort(L,r);
    sort(l,R);
}

int qi(){
    int sign=1,num=0;
    char ip=0;
    while(ip!='-'&&!(ip>='0'&&ip<='9'))ip=getchar();
    if(ip=='-'){
        sign=-1;
        ip=getchar();
    }
    while(ip>='0'&&ip<='9'){
        num=num*10+ip-'0';
        ip=getchar();
    }
    return num*sign;
}

int main(){
    freopen("P1177.in","r",stdin);
    freopen("P1177.out","w",stdout);
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        num[i]=qi();
    sort(0,N-1);
    for(int i=0;i<N;i++)
        printf("%d ",num[i]);
    return 0;
}