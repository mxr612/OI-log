#include<iostream>
#include<cstdlib>

using namespace std;

int xy[2][5],ck[2][5],ans;

int cmp(const void *a,const void *b) {
	return *(int *)a-*(int *)b;
}

int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	for(int i=1;i<5;i++) {
		cin>>xy[0][i]>>xy[1][i];
		ck[0][i]=xy[0][i];
		ck[1][i]=xy[1][i];
	}
	qsort(&ck[0][1],4,sizeof(ck[0][1]),cmp);
	qsort(&ck[1][1],4,sizeof(ck[1][1]),cmp);
	if(ck[0][1]>=xy[0][1]&&ck[0][1]<=xy[0][2]&&ck[1][1]>=xy[1][1]&&ck[1][1]<=xy[1][2]) {
		ans=(xy[0][3]-xy[0][2])*(xy[1][3]-xy[1][2]);
		ans=ans>0?ans:-1*ans;
		cout<<ans;
	}
	return 0;
}
