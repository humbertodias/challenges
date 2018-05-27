#include <cstdio>
#include <iostream>  

using namespace std;

int main()
{
  int a,b,c,d,n,i;
  int a1[4];
  int b1[4];
  int c1[4];
  int d1[4];
  while (1)//(EOF!=0)
  {
    for(i=0;i<4;i++)
    {
      cin>>a1[i]>>b1[i]>>c1[i]>>d1[i];
      if (cin.eof())return 0;
      //scanf("%d%d%d%d\n",&a1[i],&b1[i],&c1[i],&d1[i]);
    }
    //scanf("%d\n",&n);
    cin>>n;
    for(a=1;a<=4;a++)
    {
      for(b=1;b<=4;b++)
      {
        if (a!=b)
        {
          for(c=1;c<=4;c++)
          {
            if ((a!=c)&&(b!=c))
            {
              d=10-a-b-c;
              if((((a==a1[1])+(b==b1[1])+(c==c1[1])+(d==d1[1]))==n)&&
                (((a==a1[2])+(b==b1[2])+(c==c1[2])+(d==d1[2]))==n)&&
                (((a==a1[3])+(b==b1[3])+(c==c1[3])+(d==d1[3]))==n)&&
                (((a==a1[0])+(b==b1[0])+(c==c1[0])+(d==d1[0]))==n))
              {
                cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl; 
              }// printf("%d %d %d %d\n",a,b,c,d);
              
            }
          
          }
        }
      }
    }
  }
  return 0;
}
