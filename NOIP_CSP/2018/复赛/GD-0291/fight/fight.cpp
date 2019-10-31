#include<stdio.h>

#define MAX_N 100000
#define MAX_LEN 100

#define ab(a) a<0?-1*a:a
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

int n;
int p2,vp[MAX_LEN+1]={0};
int by[MAX_N+1]={0};
int m,p1,s1,s2;

int a[MAX_LEN+1]={0};
int b[MAX_LEN+1]={0};

void HpL(int a[],int b);
void HjL(int a[],int b);
void HpH(int a[],int b[]);//a+=b;
void HjH(int a[],int b[]);//a-=b�豣֤a>b 
void HcL(int a[],int b);//a*=b
int cp(int a[],int b[]);//a>b_-1 a==b_0 a<b_1
void cop(int a[],int b[]);//a<-b
void print(int a[]);

int main(){
	freopen("fight.in","r",stdin);	
	freopen("fight.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&by[i]);
	}
	scanf("%d %d %d %d",&m,&p1,&s1,&s2);
	by[p1]+=s1;
	
	for(int i=1;i<m;i++){
		HpL(a,by[i]*(m-i));
	}
	for(int i=m+1;i<=n;i++){
		HpL(b,by[i]*(i-m));
	}
	for(int i=n;i>0;i--){
		int cmp[MAX_LEN+1]={0};
		if(i<m){
			HpL(a,s2*(m-i));
		}else if(i>m){
			HpL(b,s2*(i-m));
		}
		switch(cp(a,b)){
			case -1://a>b
				HjH(a,b);
				cop(cmp,a);
				HpH(a,b);
				break;
			case 1://a<b
				HjH(b,a);
				cop(cmp,b);
				HpH(a,b);
				break;
			case 0:
				printf("%d",i);
				return 0;
			default :;
		}
		if(cp(vp,cmp)==1){
			p2=i;
			cop(vp,cmp);
		}
		if(i<m){
			HjL(a,s2*(m-i));
		}else if(i>m){
			HjL(b,s2*(i-m));
		}
	}
	printf("%d",p2);
	return 0;
}

void HpL(int a[],int b){
	int jw=0;
	a[1]+=b;
	for(int i=1;i<=MAX_LEN;i++){
		a[i]+=jw;
		jw=a[i]/10;
		a[i]%=10;
	}
}

void HjL(int a[],int b){
	int jw=0;
	for(int i=1;i<=MAX_LEN;i++){
		a[i]=a[i]-b%10-jw;
		jw=0;
		if(a[i]<0){
			a[i]+=10;
			jw=1;
		}
		b/=10;
	}
}

void HpH(int a[],int b[]){
	int jw=0;
	for(int i=1;i<=MAX_LEN;i++){
		a[i]+=b[i]+jw;
		jw=a[i]/10;
		a[i]%=10;
	}
}

void HjH(int a[],int b[]){
	int jw=0;
	for(int i=1;i<=MAX_LEN;i++){
		a[i]=a[i]-b[i]-jw;
		jw=0;
		if(a[i]<0){
			a[i]+=10;
			jw=1;
		}
	}
}

int cp(int a[],int b[]){
	for(int i=MAX_LEN;i>0;i--){
		if(a[i]>b[i]){
			return -1;
		}
		if(a[i]<b[i]){
			return 1;
		}
	}
	return 0;
}

void print(int a[]){
	int pt=MAX_LEN;
	while(a[pt]==0&&pt>0)pt--;
	if(pt==0){
		putchar('0');
	}else{
		while(pt>0){
			printf("%d",a[pt--]);			
		}
	}
}

void cop(int a[],int b[]){
	for(int i=1;i<=MAX_LEN;i++){
		a[i]=b[i];
	}
}

