// Exercício: Quadro premiado.
// Dificuldade: Médio.
// Complexidade: O(N*K^2).
// Tema: Programação Dinâmica.
// Solução: Para cada um dos K padrões, há adj[K] padrões que podem
//          estar acima e abaixo dele. Basta utilizar programação
//          dinâmica para se verificar todas as possibilidades, e
//          salva-las no estado pd[linha][padrao]. Como os problemas
//          se repetem, a complexidade final é igual a O(N*K^2),
//          pois há N*K estados, e cada um pode levar K verificações
//          para ser definido.

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;

int n, m, k;
int matriz[110][110];
char padrao[110][110];
vi adj[110];
int dp[110][110];

bool valido(int a, int b);
int soma(int a, int b);
int max(int a, int b);

int main() {
   while(1) {
      // lendo
      scanf("%d %d", &n, &m); if(!n) break;
      for(int i=0; i<n; i++) {
         for(int j=0; j<m; j++) {
            scanf("%d", &matriz[i][j]);
         }
      }
      
      // lendo
      scanf("%d", &k);
      for(int i=0; i<k; i++) {
         scanf("%s", padrao[i]);
         adj[i].clear();
      }
      
      // atribuindo adjacencias, ou seja, padroes
      // que podem ficar próximos
      for(int i=0; i<k; i++) {
         for(int j=i; j<k; j++) if(valido(i, j)) {
            adj[i].push_back(j);
            if(i != j) adj[j].push_back(i);
         }
      }
      
      // programação dinâmica, bottom-up
      int a, b, size;
      for(int i=0; i<n; i++) {
         for(int j=0; j<k; j++) {
            a = soma(i, j); b = 0;
            
            if(i) {
               size = (int)adj[j].size(); b = -INF;
               for(int l=0; l<size; l++) {
                  b = max(dp[i-1][adj[j][l]], b);
               }
            }
            
            dp[i][j] = a+b;
         }
      }
      
      // escolhendo entre os resultados finais
      int res = -INF;
      for(int i=0; i<k; i++) {
         res = max(dp[n-1][i], res);
      }
      printf("%d\n", res);
   }
}

// verifica se dois padrões podem ser adjacentes
bool valido(int a, int b) {
   for(int i=0; i<m; i++) {
      if(padrao[a][i] != '.' && padrao[a][i] == padrao[b][i]) {
         return false;
      }
   }
   return true;
}

// dada uma linha e um padrão, diz qual o valor resultante
int soma(int a, int b) {
   int res = 0;
   for(int i=0; i<m; i++) {
      if(padrao[b][i] == '+') {
         res += matriz[a][i];
      } else if(padrao[b][i] == '-') {
         res -= matriz[a][i];
      }
   }
   return res;
}

int max(int a, int b) {
   return a > b ? a : b;
}