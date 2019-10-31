#include<stdio.h>

int n,w=-1,cmp,ip[10];
bool ma[10][7]={{1,1,1,0,1,1,1},{0,0,1,0,0,1,0},{1,0,1,1,1,0,1},{1,0,1,1,0,1,1},{0,1,1,1,0,1,0},{1,1,0,1,0,1,1},{1,1,0,1,1,1,1},{1,0,1,0,0,1,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};

int main() {
	freopen("display.in","r",stdin);
	freopen("display.out","w",stdout);
	scanf("%d %d",&n,&cmp);
	for(int i=0;i<10;i++) {
		ip[i]=cmp%10;
		cmp/=10;
		w++;
		if(cmp==0) {
			break;
		}
	}
	//0
	for(int i=w;i>0;i--) {
		putchar(' ');
		for(int j=0;j<n;j++) {
			printf("%c",ma[ip[i]][0]?'-':' ');
		}
		putchar(' ');
		putchar(' ');
	}
	putchar(' ');
	for(int t=0;t<n;t++) {
		printf("%c",ma[ip[0]][0]?'-':' ');
	}
	putchar(' ');
	putchar('\n');
	//1 2
	for(int t=0;t<n;t++) {
		for(int i=w;i>0;i--) {
			putchar(ma[ip[i]][1]?'|':' ');
			for(int j=0;j<n;j++) {
				putchar(' ');
			}
			putchar(ma[ip[i]][2]?'|':' ');
			putchar(' ');
		}
		putchar(ma[ip[0]][1]?'|':' ');
			for(int j=0;j<n;j++) {
				putchar(' ');
			}
			putchar(ma[ip[0]][2]?'|':' ');
		putchar('\n');
	}
	//3
	for(int i=w;i>0;i--) {
		putchar(' ');
		for(int j=0;j<n;j++) {
			printf("%c",ma[ip[i]][3]?'-':' ');
		}
		putchar(' ');
		putchar(' ');
	}
	putchar(' ');
	for(int t=0;t<n;t++) {
		printf("%c",ma[ip[0]][3]?'-':' ');
	}
	putchar(' ');
	putchar('\n');
	//4 5
	for(int t=0;t<n;t++) {
		for(int i=w;i>0;i--) {
			putchar(ma[ip[i]][4]?'|':' ');
			for(int j=0;j<n;j++) {
				putchar(' ');
			}
			putchar(ma[ip[i]][5]?'|':' ');
			putchar(' ');
		}
		putchar(ma[ip[0]][4]?'|':' ');
		for(int j=0;j<n;j++) {
			putchar(' ');
		}
		putchar(ma[ip[0]][5]?'|':' ');
		putchar('\n');
	}
	//6
	for(int i=w;i>0;i--) {
		putchar(' ');
		for(int j=0;j<n;j++) {
			printf("%c",ma[ip[i]][6]?'-':' ');
		}
		putchar(' ');
		putchar(' ');
	}
	putchar(' ');
	for(int t=0;t<n;t++) {
		printf("%c",ma[ip[0]][6]?'-':' ');
	}
	putchar(' ');
	putchar('\n');
	return 0;
} 
