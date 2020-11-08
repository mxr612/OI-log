
#include <stdio.h>

const int frn[30]={0,31,28,31,30,31,30,31,31,30,31,30,31},
			rn[30]={0,31,29,31,30,31,30,31,31,30,31,30,31};

signed main(){
	
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);

	int Q,r,d,m,y;
	
	scanf("%d",&Q);
			
	while(Q--){
		scanf("%d",&r),++r;
		if(r<=1721424){ // BC
			y=4713-(r/1461)*4,r%=1461;
			if(r==0)y+=4,r+=1461;
			if(r>366){ //fei run nian
				--r;
				while(r>365)--y,r-=365;
				for(m=1;r>frn[m];++m)
					r-=frn[m];
				d=r;
			}else{ // run nian
				for(m=1;r>rn[m];++m)
					r-=rn[m];
				d=r;
			}
			printf("%d %d %d BC\n",d,m,y);
		}else if((r-=1721424)<=577737){ // g qian
			y=1+(r/1461)*4,r%=1461;
			if(r==0)y-=4,r+=1461;
			if(r<=1095){
				while(r>365)++y,r-=365;
				for(m=1;r>frn[m];++m)
					r-=frn[m];
				d=r;
			}else{
				y+=3,r-=1095;
				for(m=1;r>rn[m];++m)
					r-=rn[m];
				d=r;
			}
			printf("%d %d %d\n",d,m,y);
		}else if((r-=577737)<=78){ // 1582
			if(r<=17) printf("%d 10 1582\n",14+r);
			else if((r-=17)<=30) printf("%d 11 1582\n",r);
			else printf("%d 12 1582\n",r-30);
		}else if((r-=78)<=365){ // 1583
			for(m=1;r>frn[m];++m)
				r-=frn[m];
			d=r;
			printf("%d %d 1583\n",d,m);
		}else if((r-=365)<=366){ // 1584
			for(m=1;r>rn[m];++m)
				r-=rn[m];
				d=r;
			printf("%d %d 1584\n",d,m);
		}else if(true||(r-=366)<=5844){ // 1600
			y=1585+(r/1461)*4,r%=1461;
			if(r==0)y-=4,r+=1461;
			if(r<=1095){
				while(r>365)++y,r-=365;
				for(m=1;r>frn[m];++m)
					r-=frn[m];
				d=r;
			}else{
				y+=3,r-=1095;
				for(m=1;r>rn[m];++m)
					r-=rn[m];
				d=r;
			}
			printf("%d %d %d\n",d,m,y);
		}else{ //after
			y=1601+(r/146097)*400,r%=146097;
			
		}
	}
	
	return 0;
}
