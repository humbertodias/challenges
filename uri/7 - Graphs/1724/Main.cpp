#include <cstdio>

FILE *in;
int n, p1, p2, p3;
char m[128][128];
int r[128][128][128], depp;

void order(int &p1, int &p2, int &p3)
{
  int m;
  if (p1>p2)
    {
      m=p1; p1=p2; p2=m;
    }
  if (p1>p3)
    {
      m=p1; p1=p3; p3=m;
    }
  if (p2>p3)
    {
      m=p2; p2=p3; p3=m;
    }
}

int main()
{
  in = stdin;

  while(1)
    {
      fscanf(in, " %d ", &n);
      if (n==0) break;
      fscanf(in, " %d %d %d ", &p1, &p2, &p3);
      for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
      {
        fscanf(in, " %c ", &m[i][j]); 
        for(int k=0; k<n; k++)
    {
      r[i][j][k] = -1;
    }
      }
    r[i][i][i] = 0;
  }
      p1--; p2--; p3--;
      order(p1, p2, p3);

      int cnt = 0;
      depp = 1;
      while(depp)
  {
    if (r[p1][p2][p3] > -1 && r[p1][p2][p3] <= cnt) break;
          ++cnt;
    depp = 0;
    for(int i=0; i<n; i++)
      {
        for(int j=i; j<n; j++)
    {
      for(int k=j; k<n; k++)
        {
          if (r[i][j][k] != -1)
      {
        for(int l=0; l<n; l++)
          {
            if (m[l][i] == m[j][k])
        {
          int a1=l;
          int a2=j;
          int a3=k;
          order(a1,a2,a3);
          if ((r[a1][a2][a3] == -1) || (r[a1][a2][a3] > r[i][j][k]+1))
            {
              r[a1][a2][a3] = r[i][j][k]+1;
              depp = 1;
            }
        }
            if (m[l][j] == m[i][k])
        {
          int a1=l;
          int a2=i;
          int a3=k;
          order(a1,a2,a3);
          if ((r[a1][a2][a3] == -1) || (r[a1][a2][a3] > r[i][j][k]+1))
            {
              r[a1][a2][a3] = r[i][j][k]+1;
              depp = 1;
            }
        }
            if (m[l][k] == m[i][j])
        {
          int a1=l;
          int a2=i;
          int a3=j;
          order(a1,a2,a3);
          if ((r[a1][a2][a3] == -1) || (r[a1][a2][a3] > r[i][j][k]+1))
            {
              r[a1][a2][a3] = r[i][j][k]+1;
              depp = 1;
            }
        }
          }
      }
        }
    }
      }
  }

      if (r[p1][p2][p3] == -1)
  {
    printf("impossible\n");
  }
      else
  {
    printf("%d\n", r[p1][p2][p3]);
  }
    }

  return 0;
}