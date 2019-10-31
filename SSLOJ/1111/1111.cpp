#include <stdio.h>

int Low,High,Num;
int sum=0,er=0;
int InPut;

int main(int argc, char const *argv[])
{
	freopen("1111.in","r",stdin);
	scanf("%d %d %d",&Low,&High,&Num);
	for(int i=1;i<=Num;i++){
		scanf("%d",&InPut);
		
		if(InPut<Low||InPut>High){
			er++;
			if(er>(Num/10)){
				printf("0.0");
				return 0;
			}
		}else{
			sum+=InPut;
		}
	}
	printf("%.1f",1.0*sum/(Num-er));
	return 0;
}
