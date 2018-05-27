#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;
vector < vector < string > > P;
vector < string > Q;
int n;
 
int main(){
  string sing;
  string song;
  while(scanf("%d",&n) != EOF){
    P = vector < vector < string > > (n);
    Q = vector < string > (n);
    map < string,int > R;
    map < string,int > S;
    for(int i = 0;i < n;i++){
      cin >> sing >> song;
      for(int j = 0;j < sing.size();j++){
        int r = 1;
        for(int k = j;k < sing.size();k++){
          R[sing.substr(j,r)]++;
          P[i].push_back(sing.substr(j,r));
          r++;
        }
      }
      Q.push_back(song);
    }
    int res = 0;
    vector < bool > V(n,false);
    for(int i = 0;i < P.size();i++){
      int mini = (1<<30);
      for(int j = 0;j < P[i].size();j++){
        string aux = P[i][j];
        if(R[aux] > 1) continue;
        int k = aux.size();
        mini = min(mini,k);
      }
      if(mini != (1<<30)){
        V[i] = true; res += mini;
      }
    }
    P = vector < vector < string > > (n);
    for(int i = 0;i < P.size();i++){
      if(V[i]) continue;
      song = Q[i];      
      for(int j = 0;j < song.size();j++){
        int r = 1;
        for(int k = j;k < song.size();k++){
          S[song.substr(j,r)]++;
          P[i].push_back(song.substr(j,r));
          r++;
        }
      }
    }
 
    for(int i = 0;i < P.size();i++){
      if(V[i]) continue;
      int mini = (1<<30);
      for(int j = 0;j < P[i].size();j++){
        string aux = P[i][j];
        if(S[aux] > 1) continue;
        int k = aux.size();
        mini = min(mini,k);
      }
      res += mini;
    }
 
    cout << res << endl;
  }
  return 0;
}