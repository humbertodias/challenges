#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cctype>
using namespace std;
 
char in[10005];
vector< vector<char> > l_num(10001);
int t, temp, max_sum,k[10001];
 
int call_up(char x,int i,int s)
{
    int sum=s+1;
    if(max_sum<sum) max_sum=sum;
    if(isupper(x))
    {
        l_num[sum].push_back(in[i-1]);
        if(isupper(in[i-1])) 
        temp=call_up(in[i-1], i-1, sum);
 
        else temp=i-2;
 
        l_num[sum].push_back(in[temp]);
        k[sum]+=2;
        if(isupper(in[temp]))
        {
            return call_up(in[temp], temp, sum);                  
        }
        else{ return temp-1;}
    }
    return -1;
}
 
int main()
{
   scanf("%d", &t);
   while(t--)
   {
       memset(k,0,sizeof(k));
       scanf("%s", in);
       int j=strlen(in)-1;   
 
       l_num[0].push_back(in[j]);
       k[0]=1;
       call_up(in[j],j,0);
       for(int i=max_sum;i>=0;i--)
       {
               for(int l=0;l<k[i];l++)
               {
                       printf("%c", l_num[i][l]);
               }
               l_num[i].clear();
       }
       printf("\n");
   } 
   return 0;
}