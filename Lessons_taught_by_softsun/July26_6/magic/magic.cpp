#include<stdio.h> 

int n,w,dis[2000][20]={0},ans=0,l,ck,cmph,cmpw;

bool cheak(int x,int y,int l) {
	bool ans=true;
	for(int i=x;i<=x+l;i++) {
		for(int j=y;j<=y+l;j++) {
			if(dis[i][j]==1) {
				ans=false;
			}
		}
	}
	return ans;
}

int main(){
    freopen("magic.in","r",stdin);
    freopen("magic.out","w",stdout);
    scanf("%d %d",&n,&w);
    for(int t=0;t<n;t++) {
    	scanf("%d",&l);
    	for(int i=ans+1;i>0;i--) {
    		for(int j=w-l+1;j>0;j--) {
    			if(cheak(i,j,l)) {
    				cmph=i;
    				cmpw=j;
    			}
    		}
    	}
    	for(int i=cmph;i<cmph+l;i++) {
    		for(int j=cmpw;j<cmpw+l;j++) {
    			dis[i][j]=1;
    		}
    	}
/*    	for(int i=10;i>=1;i--) {
    		for(int j=1;j<=w;j++) {
    			printf("%3d",dis[i][j]);
    		}
    		printf("\n");
    	}*/
    	ans=ans>(cmph+l)?ans:(cmph+l);
//    	printf("%d %d\n",cmph,cmpw);
    } 
    printf("%d",ans);
    return 0;
}
