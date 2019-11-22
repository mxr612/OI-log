#include <stdio.h>
unsigned long long n,k,m[70];
void _print(unsigned long long x,int d,int e){
	if(d==e)
		return;
	_print(x>>1,d+1,e);
	printf("%d",x&1);
}
unsigned long long _100(unsigned long long n,unsigned long long k){
	unsigned long long x=0;
	for(int i=n;i>0;--i){
		if(k&m[i]){
			x^=m[i];
			k=(~k)+m[i+1];
		}
	}
	return x;
}
int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%llu%llu",&n,&k);
	m[1]=1;
	for(int i=2;i<=64;++i)
		m[i]=m[i-1]<<1;
	_print(_100(n,k),0,n);
	return 0;
}
