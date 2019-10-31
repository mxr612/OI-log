#include <iostream>
#include <cstdio>

using namespace std;

int n[10000];
int l=1;

void qsort(int a[],int L,int R){
	if(L>=R)
		return ;
	int l=L+1,r=R;
	int k=a[L];
	int c;
	while(l<=r){
		while(l<=r&&a[l]<k)l++;
		while(l<=r&&a[r]>k)r--;
		if(l<=r){
			c=a[l];a[l]=a[r];a[r]=c;
			l++;r--;
		}
	}
	a[L]=a[r];a[r]=k;
	qsort(a,L,r-1);
	qsort(a,l,R);
}

int main(){
	freopen("qsort.in","r",stdin);
	while(scanf("%d",&n[l])!=EOF)l++;l--;
	qsort(n,1,l);
	for(int i=1;i<=l;i++)
		cout<<n[i]<<' ';
	return 0;
}