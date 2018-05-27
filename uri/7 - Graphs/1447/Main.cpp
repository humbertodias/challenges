#include <cstdio>
#include <cstring>
using namespace std;

#define INF 1000000000
#define TAM 105

#define CLR(a, x) memset(a, x, sizeof(a))
#define min(a, b) ((a) < (b) ? (a) : (b))

int cap[TAM][TAM];
int cost[TAM][TAM];

// Estruturas auxiliares para o fluxo máximo
int deg[TAM];
int adj[TAM][TAM];
int fnet[TAM][TAM];
int par[TAM], d[TAM], pi[TAM];

#define Pot(u, v) (d[u] + pi[u] -pi[v])

bool dijkstra(int n, int s, int t)
{
    for (int i = 0; i < n; i++)
        d[i] = INF, par[i] = -1;

    d[s] = 0;
    par[s] = -n-1;

    while (1)
    {
        int u = -1, bestD = INF;
        for (int i = 0; i < n; i++)
        {
            if (par[i] < 0 && d[i] < bestD)
            {
                u = i;
                bestD = d[u];
            }
        }

        if (bestD == INF)
            break;
        
        par[u] = -par[u] - 1;

        for (int i = 0; i < deg[u]; i++)
        {
            int v = adj[u][i];
            if (par[v] >= 0) continue;
            
            if (fnet[v][u] && d[v] > Pot(u, v) - cost[v][u])
            {
                d[v] = Pot(u, v) - cost[v][u];
                par[v] = -u - 1;
            }

            if (fnet[u][v] < cap[u][v] && d[v] > Pot(u, v) + cost[u][v])
            {
                d[v] = Pot(u, v) + cost[u][v];
                par[v] = -u - 1;
            }

        }
    }

    for (int i = 0; i < n; i++)
    {
        if (pi[i] < INF)
            pi[i] += d[i];
    }

    return par[t] >= 0;
}

int maxFlowMinCost(int n, int s, int t, int max_flow, long long &fcost)
{
    CLR(deg, 0);
    CLR(fnet, 0);
    CLR(pi, 0);

    // cria matrix de adjacencia
    for (int i = 0; i < n; i++)
        for (int j= 0; j < n; j++)
            if (cap[i][j] || cap[j][i])
                adj[i][deg[i]++] = j;

    int flow = 0;
    fcost = 0;

    while (dijkstra(n, s, t))
    {
        int bot = INF;
        for (int v = t, u = par[v]; v != s; u=par[v=u])
        {
            int v_fluxo = fnet[v][u]? fnet[v][u] : (cap[u][v]-fnet[u][v]);
            bot = min(bot, v_fluxo);
            bot = min(bot, max_flow - flow);
        }
        for (int v = t, u = par[v]; v != s; u = par[v=u])
        {
            if (fnet[v][u])
            {
                fnet[v][u] -= bot;
                fcost -= bot * cost[v][u];
            }
            else
            {
                fnet[u][v] += bot;
                fcost += bot * cost[u][v];
            }
        }

        flow += bot;
        if (flow >= max_flow)
            return flow;
    }

    return flow;
}

int main()
{
    int n, m, a, b, c, d, k;
    int test = 1;
    while (scanf("%d %d", &n, &m) == 2)
    {
        if (n == 0 && m == 0)
            break;

        for (int i = 0; i <= n; i++)
        {    
            CLR(cap[i], 0);
            CLR(cost[i], 0);
        }

        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            cost[a][b] = cost[b][a] = c;
            cap[a][b] = cap[b][a] = -1;
        }

        scanf("%d %d", &d, &k);
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (cap[i][j] == -1)
                {
                    cap[i][j] = k;
                }
            }
        }

        long long min_cost = 0;
        int flow = maxFlowMinCost(n+1, 1, n, d, min_cost);
        printf("Instancia %d\n", test++);
        if (flow < d) printf("impossivel\n\n");
        else printf("%lld\n\n", min_cost);
    }

    return 0;
}
