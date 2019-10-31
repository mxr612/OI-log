#include <stdio.h>
#include <string.h>

int way[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int t;
int n,flag=1,ans;
int JL=0;
int MapOfA[1000][1000],PLofA[3];
int MapOfB[1000][1000],PLofB[3];
//A左B右

bool cheak(char in){
	bool re=true;
	switch(in){
		case 'A':
			if((PLofA[0]+way[PLofA[2]][0]<n)&&(PLofA[0]+way[PLofA[2]][0]>=0)&&(PLofA[1]+way[PLofA[2]][1]<n)&&(PLofA[1]+way[PLofA[2]][1]>=0)&&(MapOfA[PLofA[0]+way[PLofA[2]][0]][PLofA[1]+way[PLofA[2]][1]]==0)){
				re=false;
			}
			break;
		case 'B':
			if((PLofB[0]+way[PLofB[2]][0]<n)&&(PLofB[0]+way[PLofB[2]][0]>=0)&&(PLofB[1]+way[PLofB[2]][1]<n)&&(PLofB[1]+way[PLofB[2]][1]>=0)&&(MapOfA[PLofB[0]+way[PLofB[2]][0]][PLofB[1]+way[PLofB[2]][1]]==0)){
				re=false;
			}
			break;
		default:;
	}
	return re;
}


int main(int argc, char const *argv[])
{
	freopen("1106.in","r",stdin);
	scanf("%d",&t);
	for(int T=0;T<t;T++){
		memset(MapOfA,0,sizeof(MapOfA));
		memset(MapOfB,0,sizeof(MapOfB));
		JL=0;
		scanf("%d",&n);
		scanf("%d %d %d",&PLofA[0],&PLofA[1],&PLofA[2]);
		scanf("%d %d %d",&PLofB[0],&PLofB[1],&PLofB[2]);
		for(int i=1;i<=n*n&&JL==0;i++){
			MapOfA[PLofA[0]][PLofA[1]]=1;
			MapOfB[PLofB[0]][PLofB[1]]=1;
			if(PLofA[0]==PLofB[0]&&PLofA[1]==PLofB[1]){
				printf("%d %d\n",PLofA[0],PLofA[1]);
				flag=0;
				break;
			}
			while(cheak('A')&&JL<5){
				JL++;
				PLofA[2]=(PLofA[2]+4+1)%4;
			}
			JL/=5;
			PLofA[0]+=way[PLofA[2]][0];
			PLofA[1]+=way[PLofA[2]][1];
			while(cheak('B')&&JL<5){
				JL++;
				PLofB[2]=(PLofB[2]+4+1)%4;
			}
			JL/=5;
			PLofB[0]+=way[PLofB[2]][0];
			PLofB[1]+=way[PLofB[2]][1];
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					printf("%d", MapOfA[i][j]);
				}
				putchar('\n');
			}
			putchar('\n');
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					printf("%d", MapOfB[i][j]);
				}
				putchar('\n');
			}
			putchar('\n');
		}
		if(flag){
			printf("-1\n");
		}else{
			flag=1;
		}
	}
	
	return 0;
}
