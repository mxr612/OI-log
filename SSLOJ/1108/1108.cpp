
#include <stdio.h>

#define MAX_INT 10000

int n,m,p=1,cheak,t,k,ans=0;
int Map_Of_InPut[51][51]={0};
int count[MAX_INT+1]={0};

int min(int ,int);
int max(int,int);



int main(int argc, char const *argv[])
{
	freopen("1108.in","r",stdin);
	// freopen("1108.out","w",stdout);
	//InPut
	scanf("%d %d",&n,&m);
	getchar();
	for(int i=1;i<=n;i++){
		for(int j=1,cmp;j<=m;j++){
			cmp=getchar();
			if(cmp=='*'){
				Map_Of_InPut[i][j]=MAX_INT;
			}
		}
		getchar();
		p++;
	}
	//行处理
	for(int i=1;i<n;i++){
		t=0;
		for(int j=1;j<=m;j++){
			if(Map_Of_InPut[i][j]==MAX_INT){
				t=1;
				p+=t;
				continue;
			}
			if(t==1){
				Map_Of_InPut[i][j]=p;
			}
		}
		if(t==1){
			cheak=m;
			while(Map_Of_InPut[i][cheak]!=MAX_INT){
					Map_Of_InPut[i][cheak--]=0;
				}
			}
	}
	for(int j=1;j<=m;j++){
		if(Map_Of_InPut[n][j]==MAX_INT){
			continue;
		}
		Map_Of_InPut[n][j]=0;
	}
	//双向合并
	for(int i=n;i>0;i--){
		for(int j=1;j<=m;j++){
			if(Map_Of_InPut[i][j]==MAX_INT){
				continue;
			}
			if(Map_Of_InPut[i-1][j]!=MAX_INT&&Map_Of_InPut[i-1][j]!=Map_Of_InPut[i][j]){
				for(k=j;Map_Of_InPut[i-1][k]!=MAX_INT&&k>0;k++){
					Map_Of_InPut[i-1][k]=min(Map_Of_InPut[i][j],Map_Of_InPut[i-1][j]);
				}
				for(k=j;Map_Of_InPut[i-1][k]!=MAX_INT&&k<m;k--){
					Map_Of_InPut[i-1][k]=min(Map_Of_InPut[i][j],Map_Of_InPut[i-1][j]);
				}
				for(k=j;Map_Of_InPut[i][k]!=MAX_INT&&k>0;k++){
					Map_Of_InPut[i][k]=min(Map_Of_InPut[i][j],Map_Of_InPut[i-1][j]);
				}
				for(k=j;Map_Of_InPut[i][k]!=MAX_INT&&k<m;k--){
					Map_Of_InPut[i][k]=min(Map_Of_InPut[i][j],Map_Of_InPut[i-1][j]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(Map_Of_InPut[i][j]==MAX_INT){
				continue;
			}
			if(Map_Of_InPut[i+1][j]!=MAX_INT&&Map_Of_InPut[i+1][j]!=Map_Of_InPut[i][j]){
				for(k=j;Map_Of_InPut[i+1][k]!=MAX_INT&&k>0;k++){
					Map_Of_InPut[i+1][k]=min(Map_Of_InPut[i][j],Map_Of_InPut[i+1][j]);
				}
				for(k=j;Map_Of_InPut[i+1][k]!=MAX_INT&&k<m;k--){
					Map_Of_InPut[i+1][k]=min(Map_Of_InPut[i][j],Map_Of_InPut[i+1][j]);
				}
				for(k=j;Map_Of_InPut[i][k]!=MAX_INT&&k>0;k++){
					Map_Of_InPut[i][k]=min(Map_Of_InPut[i][j],Map_Of_InPut[i+1][j]);
				}
				for(k=j;Map_Of_InPut[i][k]!=MAX_INT&&k<m;k--){
					Map_Of_InPut[i][k]=min(Map_Of_InPut[i][j],Map_Of_InPut[i+1][j]);
				}
			}
		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%c",Map_Of_InPut[i][j]==MAX_INT?'*':'0');
		}
		putchar('\n');
	}
	*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(Map_Of_InPut[i][j]>0&&Map_Of_InPut[i][j]<MAX_INT){
				ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}

int min(int a,int b){
	return a<b?a:b;
}

int max(int a,int b){
	return a>b?a:b;
}
