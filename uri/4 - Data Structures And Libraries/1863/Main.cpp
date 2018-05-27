#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 50500
#define MAXC 1100

#define F first
#define S second
#define PB push_back

typedef pair<int,int> ii;

int n, m, segtree[4*MAXC][4*MAXC], in_deg[MAXN], resp;
 
vector<int> sons[MAXN];

vector<ii> dot;

int maior_aux(int y1, int y2, int superseg, int seg=1, int ini_y=1, int fim_y=1000){
    
    if(y1>fim_y or y2<ini_y) return 0;
    
    if(ini_y>=y1 and fim_y<=y2) return segtree[superseg][seg];
    
    int meio_y=(ini_y+fim_y)/2;
    
    return max(maior_aux(y1,y2,superseg,2*seg,ini_y,meio_y),maior_aux(y1,y2,superseg,2*seg+1,meio_y+1,fim_y));
}

int maior(int x1, int y1, int x2, int y2, int seg=1, int ini_x=1, int fim_x=1000){
    
    //cout << "maior(" << x1 << "," << y1 << "," << x2 << "," << y2 << "," << seg << "," << ini_x << "," << fim_x << ")\n";
    
    if(x1>fim_x or x2<ini_x) return 0;
    
    if(ini_x>=x1 and fim_x<=x2) return maior_aux(y1,y2,seg);
    
    int meio_x=(ini_x+fim_x)/2;
    
    return max(maior(x1,y1,x2,y2,2*seg,ini_x,meio_x),maior(x1,y1,x2,y2,2*seg+1,meio_x+1,fim_x));
}

void update_aux(int delta, int y, int superseg, int seg=1, int ini_y=1, int fim_y=1000){
    if(y>fim_y or y<ini_y) return;
    
    if(ini_y==fim_y and fim_y==y){
        segtree[superseg][seg]=delta;
        return;
    }
    
    int meio_y=(ini_y+fim_y)/2;
    
    update_aux(delta,y,superseg,2*seg,ini_y,meio_y);
    update_aux(delta,y,superseg,2*seg+1,meio_y+1,fim_y);
    
    segtree[superseg][seg]=max(segtree[superseg][2*seg],segtree[superseg][2*seg+1]);
}

void merge(int superseg, int y, int seg=1, int ini_y=1, int fim_y=1000){
    
    if(y<ini_y or y>fim_y) return;
    
    segtree[superseg][seg]=max(segtree[2*superseg][seg],segtree[2*superseg+1][seg]);
    
    if(ini_y==fim_y and ini_y==y) return;
    
    int meio_y=(ini_y+fim_y)/2;
    
    merge(superseg,y,2*seg,ini_y,meio_y);
    merge(superseg,y,2*seg+1,meio_y+1,fim_y);
}

void update(int delta, int x, int y, int seg=1, int ini_x=1, int fim_x=1000){
    
    if(x>fim_x or x<ini_x) return;
    
    if(ini_x==fim_x and fim_x==x){
    
        update_aux(delta,y,seg);
        
        return;
    }
    
    int meio_x=(ini_x+fim_x)/2;
    
    update(delta,x,y,2*seg,ini_x,meio_x);
    update(delta,x,y,2*seg+1,meio_x+1,fim_x);
    
    merge(seg, y); 
}

void compress(){
    
    vector<int> ori_x, ori_y;
    
    for(int i=0; i<n; i++) ori_x.PB(dot[i].F), ori_y.PB(dot[i].S);
    
    sort(ori_x.begin(),ori_x.end());
    sort(ori_y.begin(),ori_y.end());
    
    ori_x.resize(unique(ori_x.begin(),ori_x.end())-ori_x.begin());
    ori_y.resize(unique(ori_y.begin(),ori_y.end())-ori_y.begin());
    
    for(int i=0; i<n; i++) dot[i].F=1+(lower_bound(ori_x.begin(),ori_x.end(),dot[i].F)-ori_x.begin());
    for(int i=0; i<n; i++) dot[i].S=1+(lower_bound(ori_y.begin(),ori_y.end(),dot[i].S)-ori_y.begin());
}

void dfs(int v){
    
    //cout << "DFS(" << v << ")\n";
    
    int x=dot[v].F, y=dot[v].S;
    
    //cout << "v=(" << x << "," << y << ")\n";
    
    //cout << "OK 1\n";
    
    int len=(x>1 and y>1)?maior(1,1,x-1,y-1):0;
    
    //cout << "OK 2\n";
    
    resp=max(resp,len+1);
    
    update(len+1,x,y);
    
    //cout << "OK 3\n";
    
    for(int i=0; i<sons[v].size(); i++) dfs(sons[v][i]);
    
    update(0,x,y);
}

int main(){
    
    ios_base::sync_with_stdio(false), cin.tie(0);
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        
        int x, y;
        cin >> x >> y;
        
        dot.PB(ii(x,y));
    }
    
    compress();
    
    for(int i=0; i<m; i++){
        
        int v, u;
        cin >> v >> u;
        
        v--,u--;
        
        sons[v].PB(u);
        in_deg[u]++;
    }
    
    //cout << "vai comecar a DFS\n";
    
    for(int v=0; v<n; v++)
        if(!in_deg[v]){
            
            //cout << "chamando pra " << v << "\n";
            
            dfs(v);
        }
    
    cout << resp << "\n";
    
    return 0;
}