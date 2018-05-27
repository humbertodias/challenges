#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

#define MAXN 55
#define MAXS 1100
#define INF 0x3f3f3f3f

#define PB push_back
#define F first
#define S second

typedef long long ll;
typedef pair<int, ll> ii;

vector<int> s1, s2, seq;

int n, x, y, previous[3][MAXN][MAXS], dp[MAXS][MAXS];

ll qtd[MAXS][MAXS];

void read(int tam, vector<int> &s){
  
  for(int i=0; i<tam; i++){
    
    int k;
    cin >> k;
    
    s.PB(k);
  }
}

void prep(int k, vector<int> &s){
  
  for(int i=1; i<=n; i++){
      
    int p=-1;
      
    for(int j=0; j<s.size(); j++){
        
      if(i==s[j]) p=j;
        
      previous[k][i][j+1]=p;
    }
  }
}

ii solve(int tam1, int tam2){
  
  if(dp[tam1][tam2]) return ii(dp[tam1][tam2], qtd[tam1][tam2]);
  
  if(!tam1 or !tam2){
    
    dp[tam1][tam2]=1;
    qtd[tam1][tam2]=n;
    
    return ii(dp[tam1][tam2], qtd[tam1][tam2]);
  }
  
  ii resp=ii(INF,0);
  
  for(int k=1; k<=n; k++){
    
    if(previous[1][k][tam1]<0 or previous[2][k][tam2]<0){
      
      if(resp.F==1) resp.S++;
      else resp=ii(1,1);
    }
    
    else{
      
      ii davez=solve(previous[1][k][tam1], previous[2][k][tam2]);
      davez.F+=1;
      
      if(resp.F==davez.F) resp.S+=davez.S;
      if(resp.F>davez.F) resp=davez; 
    }
  }
  
  dp[tam1][tam2]=resp.F;
  qtd[tam1][tam2]=resp.S;
    
  return resp;
}

int main(){
  
  ios_base::sync_with_stdio(false);
  
  while(cin >> n >> x >> y){
    
    memset(dp, 0, sizeof dp);
    
    s1.clear(), s2.clear();
    
    read(x, s1), read(y, s2);
  
    prep(1, s1), prep(2, s2);
    
    ii resp=solve(x, y);
    
    cout << resp.F << " " << resp.S << "\n";
  }
  
  return 0;
}
