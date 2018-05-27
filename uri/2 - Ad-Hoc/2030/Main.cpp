#include<stdio.h>
#define ll unsigned long long int

int main()
{
   int i,N,A,B,C,D,E,cont;
   ll tot;
   scanf("%d",&N);
   for(i=1;i<=N;i++)
   {
      tot=0;
      cont=0;
      scanf("%d %d %d %d %d",&A,&B,&C,&D,&E);
      while(E>0)
      {
         if(E>D)
         {
            if(A*D+B*(E-D)>A*E+C*(E/D))
            {
               cont++;
               tot += A*D+C;
            }
            else
            {
               tot += A*D+B*(E-D);
               break;
            }
         }
         else
            tot += A*E;
         E -= D;
      }
      printf("Teste #%d\n%lld %d\n\n",i,tot,cont);
   }
   return 0;
}