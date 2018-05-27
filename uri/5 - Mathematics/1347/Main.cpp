#include <cmath>
#include <vector>
#include <cstring>
#include <cstdio>
#include <queue>
#include <ostream>

using namespace std;
double EPS = 1e-12;

struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};
double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")"; 
}

bool LinesParallel(PT a, PT b, PT c, PT d) { 
  return fabs(cross(b-a, c-d)) < EPS; 
}

bool LinesCollinear(PT a, PT b, PT c, PT d) { 
  return LinesParallel(a, b, c, d)
      && fabs(cross(a-b, a-c)) < EPS
      && fabs(cross(c-d, c-a)) < EPS; 
}

bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
  if (LinesCollinear(a, b, c, d)) return false;
  if (cross(d-a, b-a) * cross(c-a, b-a) >= 0) return false;
  if (cross(a-c, d-c) * cross(b-c, d-c) >= 0) return false;
  return true;
}
int n, m, l;
pair<PT,PT> lines[60];
PT teleport[60];
PT start, exito;
PT points[1010];
bool tp[1010];
class edge{
	public:
	int from, to;
	double dist;
	edge(){}
	edge(int a, int b, double c){
		from = a; to = b; dist = c;
	}
};
class node{
	public:
	int n, l; double dist;
	node(){}
	node(int a, int b, double c){
		n = a; l = b; dist = c;
	}
	bool operator<(const node& other) const{
		return other.dist+EPS<dist;
	}
};
vector<edge> graph[210];
double visited[210][60];
double dijkstra(int S, int E){
	priority_queue<node> pq;
	pq.push(node(S,0,0.0));
	
	for(int i=0; i<=200; i++){
		for(int j=0; j<=n; j++){
			visited[i][j] = 1e20;
		}
	}
	visited[S][0] = 0.0;
	while(!pq.empty()){
		node cur = pq.top(); pq.pop();
		if(cur.n==E) return cur.dist;
		for(int i=0; i<(int)graph[cur.n].size(); i++){
			int next = graph[cur.n][i].to;
			double next_dist = cur.dist+graph[cur.n][i].dist;
			if(tp[cur.n] && tp[next]){
				if(cur.l<n){
					if(!(visited[next][cur.l+1]<=cur.dist)){
						visited[next][cur.l+1] = cur.dist;
						pq.push(node(next, cur.l+1, cur.dist));
					}
				}
			}
			if(visited[next][cur.l]<=next_dist) continue;
			visited[next][cur.l] = next_dist;
			pq.push(node(next, cur.l, next_dist));
		}
	}
	return visited[100000][100000]; /* NO DEBERIA PASAR, EL ENUNCIADO NO DICE */
}
int main(){
	while(scanf("%d %d %d", &n, &m, &l) && !(n==0 && m==0 && l==0)){
		memset(tp, false, sizeof(tp));
		for(int i=0; i<m; i++){
			scanf("%lf %lf %lf %lf", &lines[i].first.x, &lines[i].first.y, &lines[i].second.x, &lines[i].second.y);
		}
		for(int i=0; i<l; i++){
			scanf("%lf %lf", &teleport[i].x, &teleport[i].y);
		}
		scanf("%lf %lf %lf %lf", &start.x, &start.y, &exito.x, &exito.y);
		int tam = 0;
		for(int i=0; i<m; i++){
			points[tam++] = lines[i].first;
			points[tam++] = lines[i].second;
		}
		int S = tam, E = tam+1;
		points[tam++] = start;
		points[tam++] = exito;
		for(int i=0; i<l; i++){
			tp[tam] = true;
			points[tam++] = teleport[i];
		}
		for(int i=0; i<tam; i++){
			for(int j=i+1; j<tam; j++){
				pair<PT,PT> line = make_pair(points[i], points[j]);
				bool ok = false;
				for(int k=0; k<m; k++){
					ok = ok || SegmentsIntersect(line.first, line.second, lines[k].first, lines[k].second);
				}
				if(!ok){
					//printf("%d %d\n", i, j);
					double dist_val;
					dist_val = sqrt(dist2(line.first, line.second));
					graph[i].push_back(edge(i,j,dist_val));
					graph[j].push_back(edge(j,i,dist_val));
				}
			}
	 	}
		double ans = dijkstra(S,E);
		ans = round(ans);
		printf("%.0lf\n", ans);
		for(int i=0; i<=tam; i++) graph[i].clear();
	}	
	return 0;
}