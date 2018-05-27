#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void conexos(int** g, int ordem){
  vector <int> elem;
  int status[ordem];
  int ini = 0;
  int pilha[ordem];
  int topo = -1;
  int cont = 0;
  char a;

  // inicializa status
  for (int i = 0; i < ordem; ++i)
    status[i] = 0;


  for (int j = 0; j < ordem; ++j) {
    if(status[j] == 0){
      status[j] = 1;
      pilha[++topo] = j;

      while(topo != -1){
        ini = pilha[topo--];
        elem.push_back(ini);
        for (int i = 0; i < ordem; ++i) {
          if(g[ini][i] && status[i] == 0){
            pilha[++topo] = i;
            status[i] = 1;
          }
        }
      }

      sort(elem.begin(), elem.end());

      for (int i = 0; i < elem.size(); ++i){
        a = elem[i] + 97;
        cout << a<< ",";
      }
      cout << endl;
      elem.clear();
      cont++;
    }
  }

  cout << cont << " connected components" << endl;


}

int main(){

  char c1,c2;
  int n,v,e,x,y;

  cin >> n;

  for (int i = 1; i <= n; ++i){
    cin >> v >> e;

    // inicializa grafo
    int** g = new int*[v];
    for (int j = 0; j < v; ++j){
      g[j] = new int[v];
      for (int k = 0; k < v; ++k) 
        g[j][k] = 0;      
    }
    
    // leitura de valores
    for (int j = 0; j < e; ++j) {
      cin >> c1 >> c2;
      x = (int)c1 - 97;
      y = (int)c2 - 97;
      g[x][y] = 1;
      g[y][x] = 1;
    }
    cout << "Case #" << i << ":" << endl;
    conexos(g,v);
    cout << endl;

  }

}