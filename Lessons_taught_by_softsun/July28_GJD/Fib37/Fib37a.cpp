#include<iostream> 
using namespace std;

#define MAX 10000

short n=2,num[3][MAX]={0};

void ad(short ip) {
	int a=ip%3,b=(ip+1)%3,c=(ip+2)%3,g=0;
	for(int i=1;i<MAX;i++) {
		num[a][i]=num[b][i]+num[c][i]+g;
		g=num[a][i]/10;
		num[a][i]%=10;
	}
}

void print(short ip) {
	int fi=MAX,a=ip%3;
	while(num[a][fi]==0)fi--;
	while(fi>0)cout<<num[a][fi--];
	cout<<endl;
}

bool qck3(short ip) {
	short cmp=0,a=ip%3;
	for(int i=1;i<MAX;i++) {
		cmp+=num[a][i];
		cmp%=3;
	}
	if(cmp==0) {
		return false;
	}else{
		return true;
	}
}

bool qck7(short ip) {
	int fi=MAX,a=ip%3,g=0;
	while(num[a][fi]==0)fi--;
	while(fi>0) {
		g=(g*10+num[a][fi--])%7;
	}
	if(g==0) {
		return false; 
	}else{
		return true;
	}
}
	

int main() {
	freopen("out.out","w",stdout);
	num[0][1]=1;
	num[1][1]=1;
	cout<<1<<endl<<1<<endl;
	while(n<1001) {
		ad(n);
		if(qck3(n)&&qck7(n)){
			print(n);
		}
		n++;
	}
	return 0;
} 
