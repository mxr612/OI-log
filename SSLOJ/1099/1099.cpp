#include <iostream>
#include <cstdlib>
using namespace std;

int N;
int num[30001]={0};

int qcmp(const void *a,const void *b){
	return *(int *)a-*(int *)b;
}

int main(int argc, char const *argv[])
{
	// freopen("1099.in","r",stdin);
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>num[i];
	}
	qsort(&num[1],N,sizeof(num[0]),qcmp);
	if(N%2){
		cout<<num[N/2+1];
	}else{
		cout<<(num[N/2]+num[N/2+1])/2;
	}
	return 0;
}
