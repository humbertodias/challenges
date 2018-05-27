#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 512
#define INFTO 112345678

typedef struct{ int x, y; }ponto;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<pii> vpi;

int N, M, dist[MAX][MAX];
ponto s, t;
char grid[MAX][MAX], ok[MAX][MAX];

void dijkstra(){
  ponto u, v;
  int peso, i, j;
  int dx[] = {0, 0, 1, -1}, dy[] = { 1, -1, 0, 0};
  priority_queue< pii, vpi, greater<pii> > Q;
  memset(ok, 0, sizeof(ok));
  for(i = 0; i < N; i++)
    for(j = 0; j < M; j++) dist[i][j] = INFTO;
  dist[s.x][s.y] = 0; Q.push(pii(0, ii(s.x, s.y)));
  while(!Q.empty()) {
    u.x = Q.top().second.first; u.y = Q.top().second.second;
    Q.pop();
    if(ok[u.x][u.y]) continue;
    ok[u.x][u.y] = 1;
    for(i = 0; i < 4; i++){
      v.x = u.x + dx[i]; v.y = u.y + dy[i];
      peso = grid[v.x][v.y] == '.' || grid[v.x][v.y] == 'E' ? 0 : grid[v.x][v.y] - '0';
      if(v.x >= 0 && v.x < N && v.y >= 0 && v.y < M && grid[v.x][v.y] != '#' && grid[v.x][v.y] != 'H' && dist[v.x][v.y] > dist[u.x][u.y] + peso){
        dist[v.x][v.y] = dist[u.x][u.y] + peso;
        Q.push(pii(dist[v.x][v.y], ii(v.x, v.y)));
      }}}
  if(dist[t.x][t.y] != INFTO) printf("%d\n", dist[t.x][t.y]);
  else printf("ARTSKJID\n");
}

int main(void){
  int i, j;
  scanf("%d %d", &N, &M);
  for(i = 0; i < N; i++){
    getchar();
    for(j = 0; j < M; j++){
      grid[i][j] = getchar();
      if(grid[i][j] == 'H'){ s.x = i; s.y = j; }
      if(grid[i][j] == 'E'){ t.x = i; t.y = j; }
    }}
  dijkstra();
  return 0;
}