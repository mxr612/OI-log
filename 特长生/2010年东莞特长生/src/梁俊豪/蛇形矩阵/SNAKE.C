#include <stdio.h>

int main()
{
   FILE *fp;
   int N,i,j;
   int x=1,y=1,num;
   int flag=1;
   fp=fopen("snake.in","r");
   int a[N+1][N+1];
   fscanf(fp,"%d",&N);
   fclose(fp);
   num=N*N;
   for(i=1;i<=N;i++,flag=1)
      for(j=1;j<=i;j++)
      {
         if(flag)
         {
            if(i%2==0) {x=j; y=i;}
	    else {x=i;y=j;}
         }
         if(i%2==0) a[x++][y--]=num--;
         else a[x--][y++]=num--;
      }
   fp=fopen("snake.out","w+");
   for(i=1;i<=N;i++)
   {
      for(j=1;j<=N;j++) fprintf(fp,"%d",a[i][j]);
      fprintf(fp,"\n");
   }
   fclose(fp);
   return 0;
}