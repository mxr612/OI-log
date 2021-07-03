#include <stdio.h>

int main()
{
   int i,n=1;
   int K;
   unsigned long S=1;
   FILE *fp;
   fp=fopen("minnum.in","r");
   fscanf(fp,"%d",&K);
   fclose(fp);
   while(S<=K)
   {
      n++;
      S+=1/n;
   }
   fp=fopen("minnum.out","w+");
   fprintf(fp,"%d",n);
   fclose(fp);
   return 0;
}
