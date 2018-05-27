#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <utility> // pair
#include <string>
#include <unordered_map>
#include <algorithm> // reverse

using namespace std;
 
typedef unsigned long long int ull;
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
#define rep(i,n) for(int i = 0; i < n; i++)
#define INF    0x3f3f3f3f
#define NEGINF 0xC0C0C0C0
#define LINF   0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(), v.end()
#define NULO -1
#define EPS 1e-10
#define PI 2 * acos(0)
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s))
#define F first
#define S second
 
inline int cmp(double x, double y = 0, double tol = EPS)
{ return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1; }
 
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
 
string final = "123456780";
 
bool inGrid(int i, int j)
{
   if(i < 0 || i >= 3 || j < 0 || j >= 3)
      return false;
   return true;
}
 
typedef pair<string, int> si;
unordered_map<string, string> pai;
 
void bfs(string inicio)
{
   set<string> visitados;
   pai.clear();
   queue<si> q;
   q.push(si(inicio, 0));
   visitados.insert(inicio);
 
   while(!q.empty())
   {
      si f = q.front(); q.pop();
      string topo = f.first;
      int passos = f.second;
 
 
      if(topo == final)
         break;
 
      int idx = 0;
      for(idx = 0; idx < topo.size(); idx++)
         if(topo[idx] == '0')
            break;
 
      int x = idx / 3;
      int y = idx % 3;
      for(int i = 0; i < 4; i++)
      {
         int novoX = x + dx[i];
         int novoY = y + dy[i];
         int novoIdx = novoX * 3 + novoY;
         string aux = topo;
         if(inGrid(novoX, novoY))
         {
            swap(aux[idx], aux[novoIdx]);
            if(visitados.find(aux) == visitados.end())
            {
               pai[aux] = topo;
               q.push(si(aux, passos + 1));
               visitados.insert(aux);
            }
         }
      }
   }
}
 
int main()
{
 
   //freopen("slidingPuzzle8.in", "rt", stdin);
   //freopen("slidingPuzzle8.out", "wt", stdout);
   string str, s;
   while(cin >> str)
   {
      cin >> s;
      str += s;
      cin >> s;
      str += s;
 
      pai.clear();
      bfs(str);
 
      if(pai.find(final) == pai.end())
      {
         printf("Problema sem solucao\n");
         continue;
      }
 
      vector<string> sol;
      string ini = final;
      while(pai.find(ini) != pai.end())
      {
         sol.pb(ini);
         ini = pai[ini];
      }
 
      reverse(sol.begin(), sol.end());
 
      printf("Quantidade minima de passos = %d", (int)sol.size());
      for(auto s : sol)
      {
         for(int i = 0; i < 9; i++)
         {
            if(i % 3 == 0)
               printf("\n");
            printf("%c", s[i]);
         }
         printf("\n");
      }
   }
   return 0;
}