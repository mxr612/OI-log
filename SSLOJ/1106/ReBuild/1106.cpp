// 1106.cpp

#include <stdio.h>
#include <string.h>

const int WAY[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int times,n;
int MapOfA[1000][1000]={0},PLofA[3],KillA;
int MapOfB[1000][1000]={0},PLofB[3],KillB;

void once();
void walk(char);
bool cheak(char);
void print(char);

int main(int argc, char const *argv[])
{
	freopen("1106.in","r",stdin);
	scanf("%d",&times);
	for(int t=1;t<=times;t++){
		once();
	}
	return 0;
}

void once(){
	KillA=KillB=0;
	memset(MapOfA,0,sizeof(MapOfA));
	memset(MapOfB,0,sizeof(MapOfB));
	scanf("%d\n",&n);
	scanf("%d %d %d\n",&PLofA[0],&PLofA[1],&PLofA[2]);
	scanf("%d %d %d\n",&PLofB[0],&PLofB[1],&PLofB[2]);
	for(int i=0;i<=n*n;i++){
		if(PLofA[0]==PLofB[0]&&PLofA[1]==PLofB[1]){
			printf("%d %d\n",PLofA[0],PLofA[1]);
			break ;
		}
		if(KillA&&KillB){
			printf("-1\n");
			break ;
		}
		walk('A');
		print('A');
		walk('B');
		print('B');
	}
}

void walk(char c){
	if((c=='A'&&KillA)||(c=='B'&&KillB)){
		return ;
	}
	if(c=='A'){
		MapOfA[PLofA[0]][PLofA[1]]=1;
		while(cheak('A')&&KillA<5){
			PLofA[2]=(PLofA[2]+1)%4;
			KillA++;
		}
		KillA=(int )KillA / 5;
		if(KillA==0){
			PLofA[0]+=WAY[PLofA[2]][0];
			PLofA[1]+=WAY[PLofA[2]][1];
		}
	}else{
		MapOfB[PLofB[0]][PLofB[1]]=1;
		while(cheak('B')&&KillB<5){
			PLofB[2]=(PLofB[2]+1)%4;
			KillB++;
		}
		KillB=(int )KillB / 5;
		if(KillB==0){
			PLofB[0]+=WAY[PLofB[2]][0];
			PLofB[1]+=WAY[PLofB[2]][1];
		}
	}
}

bool cheak(char c){
	bool re=false;
	if(c=='A'){
		if((PLofA[0]+WAY[PLofA[2]][0])<0)re=true;
		if((PLofA[0]+WAY[PLofA[2]][0])>=n)re=true;
		if((PLofA[1]+WAY[PLofA[2]][1])<0)re=true;
		if((PLofA[1]+WAY[PLofA[2]][1])>=n)re=true;
		if(!re)
			if(MapOfA[PLofA[0]+WAY[PLofA[2]][0]][PLofA[1]+WAY[PLofA[2]][1]]==1)re=true;
	}else{
		if((PLofB[0]+WAY[PLofB[2]][0])<0)re=true;
		if((PLofB[0]+WAY[PLofB[2]][0])>=n)re=true;
		if((PLofB[1]+WAY[PLofB[2]][1])<0)re=true;
		if((PLofB[1]+WAY[PLofB[2]][1])>=n)re=true;
		if(!re)
			if(MapOfB[PLofB[0]+WAY[PLofB[2]][0]][PLofB[1]+WAY[PLofB[2]][1]]==1)re=true;
	}
	return re;
}

void print(char c){
	if(c=='A'){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%d",MapOfA[i][j]);
			}
			putchar('\n');
		}
		putchar('\n');
	}else{
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%d",MapOfB[i][j]);
			}
			putchar('\n');
		}
		putchar('\n');
	}
	
}
