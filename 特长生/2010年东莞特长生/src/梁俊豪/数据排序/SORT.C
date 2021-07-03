#include <stdio.h>

struct stu
{
   int num;
   int grade;
};

int main()
{
   FILE *fp;
   int N,i,j;
   int rank=1;
   fp=fopen("sort.in","r");
   fscanf(fp,"%d",&N);
   struct stu a[N],*p[N],*temp;
   for(i=0;i<N;i++)
   {
      p[i]=&a[i];
      fscanf(fp,"%d%d",&p->num,&p->grade);
   }
   fclose(fp);
   for(i=0;i<N-1;i++)
      for(j=i+1;j<N;j++)
      {
         if(p[i]->grade<p[j]->grade)
         {
            temp=p[i];
            p[i]=p[j];
            p[j]=temp;
         }
         else if(p[i]->grade==p[j]->grade&&p[i]->num>p[j]->num)
         {
            temp=p[i];
            p[i]=p[j];
            p[j]=temp;
         }
      }
   fp=fopen("sort.out","w+");
   fprintf(fp,"%d %d %d",p->num,p->grade,rank);
   for(i=1;i<N;i++)
   {
      if(p[i]->grade!=p[i-1]->grade) rank++;
      fprintf(fp,"%d %d %d",p->num,p->grade,rank);
   }
   fclose(fp);
   return 0;
}
