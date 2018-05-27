#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#define MAX 10002
#define inf 1000000000
using namespace std;
int n,m;
typedef long long int lli;
pair < lli, lli > dist[MAX];
int mrc[MAX];
vector < pair <int , pair <int , int  > > > lista[MAX];
void init()
{
    for(int i=0;i<=n;i++)
    {
        dist[i].first = inf;
        dist[i].second = inf;
        mrc[i] = 0;
        lista[i].clear();
    }
}
void dij(lli s,lli tempL,lli D)
{
    for(int i=0;i<=n;i++)
    {
        dist[i].first = inf;
        dist[i].second = inf;
        mrc[i] = 0;
    }
    dist[s].first = 0;
    dist[s].second = 0;
    set < pair < lli,int > > c;
    c.insert(make_pair(dist[s].first,s));
    while(!c.empty())
    {
        int v = (*c.begin()).second;
        c.erase(*c.begin());
        for( int i =0; i < lista[v].size();i++)
        {
            int u = lista[v][i].first;
 
            if(mrc[u] || (lista[v][i].second.second + dist[v].second >= tempL && u!=D) )
                continue;
 
            if(dist[u].first > (dist[v].first + lista[v][i].second.first) && (dist[v].second + lista[v][i].second.second) <= tempL)
            {
                dist[u].first = dist[v].first + lista[v][i].second.first;
                dist[u].second = dist[v].second + lista[v][i].second.second; 
                c.insert(make_pair(dist[u].first,u));
            }
 
        }
        mrc[v] = 1;
    }
}
int main()
{
    int cnt = 1;
    while(scanf("%d%d",&n,&m) && n != 0 && m != 0)
    {
        init();
        for(int i =0; i < m; i++)
        {
            int x,y,c,t;
            scanf("%d%d%d%d",&x,&y,&c,&t);
            lista[x].push_back(make_pair(y,make_pair(c,t)));
        }
 
 
        lli qtde;
        scanf("%lld",&qtde);
        if(cnt > 1)
            printf("\n");
        printf("Instancia %d\n",cnt++);
        while(qtde--)
        {
            long long O,D,tempL;
            scanf("%lld%lld%lld",&O,&D,&tempL);
            dij(O,tempL,D);
            if(dist[D].first < inf && dist[D].second <=tempL)
            {
                printf("Possivel - %lld km, %lld min\n",dist[D].first,dist[D].second);
            }
            else
                printf("Impossivel\n");
        }
 
    }
    return 0;
}