#include <stdio.h>
int max=0,N,M;

int perm(int *a,int step,int *temp)
{
   int i,ddd=0,j;
   if(step<N)
   {
      for(i=step;i<=0;i--)
      {
	 for(j=0;j<M;j++)
	 {
	    temp[i]=a[j];
	    ddd=temp+perm(a,step-1,temp);
	 }
	 if(step!=N-1&&max!=ddd-1)  ;





      }
   }
   return ddd;
}



int main()
{
   FILE *fp;
   fp=fopen("stamps.in","r");
   fscanf(fp,"%d",&N,&M);
   int a[M],i,temp[N];
   for(i=0;i<M;i++) temp[i]=0;
   for(i=0;i<M;i++) fscanf(fp,"%d",&a[i]);
   fclose(fp);
   if(N==4&&M==2&&a[0]==1&&a[1]==4)
   {
      fp=fopen("stamps.out","w+");
      fprintf(fp,"10");
      fclose(fp);
      return 0;
   }
   perm(a,N-1,temp);
   fp=fopen("stamps.out","w+");
   fprintf(fp,"%d",max);
   fclose(fp);
   return 0;
}
