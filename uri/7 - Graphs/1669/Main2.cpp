
#include<iostream>
#include<vector>
#include<stack>
#include<deque>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef stack<int> st;
typedef vector<bool> vb;
typedef deque<int> deq;
void topo(vvi &graph,int n,vb & visited,deq &stak)
{
        visited[n]=1;
        vi::iterator it;
        for(it=graph[n].begin();it!=graph[n].end();++it)
        {
                if(visited[*it]==0)
                      topo(graph,*it,visited,stak);
        }
        stak.push_front(n);
} 
int main()
{
      int n1,n2,d,i,x,y,steps=2,ele,clr,size,j,k,clr1,ele1;
      while(1)
      {
             deq stak;
             steps=2;
             cin>>n1>>n2>>d;
             if(n1==0&&n2==0&&d==0) break;
             vi dependent(n1+n2+1,0);
             vb installed(n1+n2+1,0);
             vvi graph(n1+n2+1);
             int color[n1+n2+1];
             vector<bool> visited(n1+n2+1,0);
             for(i=0;i<=n1;i++)
             {
                    color[i]=0;
             }
             for(i=1;i<=n2;i++)
             {
                    color[n1+i]=1;
             }
   /*for(i=1;i<=n1+n1;i++)
                     cout<<i<<" "<<color[i]<<endl;*/
             for(i=1;i<=d;i++)
             {
                       cin>>x>>y;
                       graph[y].push_back(x);
                       dependent[x]++;
             }
             for(i=1;i<=n1+n2;i++)
             {
                      if(visited[i]==0)
                      topo(graph,i,visited,stak);
             }
             size=stak.size();
             /*for(i=0;i<size;++i)
             {
                         j=stak[i];
                         cout<<stak[i]<<" "<<color[j]<<endl;
             }*/
             clr=color[0];
             for(i=0;i<n1+n2;i++)
             {
               
                   ele=stak[i];
                   if(installed[ele]==1)
                            continue;
                   clr=color[ele];
                   if(i!=0)
                   {
                     
                      if(clr!=clr1)
                        steps++;
                        clr1=clr;
                   }                           
                   installed[ele]=1;
                  /*reducing dependency*/
                  for(j=0;j<graph[ele].size();j++)
                  {
                     x=graph[ele][j];
                     dependent[x]--;
                  }
                  /*finding same color*/
                  for(j=i+1;j<n1+n2;j++)
                  {
                     x=stak[j];
                     if(clr==color[x])
                     {
                        if(dependent[x]<=0)
                        {
                           if(installed[x]==0)
                           {
                              installed[x]=1;
                              for(k=0;k<graph[x].size();k++)
                              {
                                  y=graph[x][k];
                                  dependent[y]--;
                              }
                           }
                        }
                      }
                    }
                    ele1=ele;
                    clr1=clr;
                 }
                  cout<<steps<<endl;
         }
         return 0;
}