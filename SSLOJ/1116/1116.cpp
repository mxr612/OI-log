// 1116.cpp

#include <stdio.h>

int N;
char stringes[60][60]={0};

int main(int argc, char const *argv[])
{
	freopen("1116.in","r",stdin);
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%s",stringes[i]);
	}
	for(int i=1;i=N;i++){//找第i个的前缀
		for(int j=N,ck_j=1;j>0;j++){//枚举最高位数
			ck_j=0;
			for(int k=1,ck_k=0;i<N;i++){//枚举被检查string
				for(int l=1;l<=j;l++){//逐位检查前缀
					if(stringes[i][l]!=stringes[k][l]){
						ck_k=1;
						break;
					}
				}
				if(ck_k==0){
					ck_j=0;
					break;
				}
			}
			if(ck_j==1){

			}
		}
	}
	return 0;
}
