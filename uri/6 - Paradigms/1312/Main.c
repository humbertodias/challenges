#include <stdio.h>
#define MAX 1001

/*
maxLinha
CB: um elemento, nesse caso o melhor é ele mesmo.
HI: Para n - 1 elementos, para n > 1, sabemos o melhor valor a partir do primeiro elemento k até n.
PI: Dados n números, retiramos seu primeiro (k) obtendo n - 1 números. Por HI sabemos a melhor sequência de soma para ele, e não só isso, que o elemento v[k + 1] tem este valor.
Voltando k, temos que analizar o valor de k + 1 (v[k + 1]): se este é negativo, a melhor soma para k é ele próprio (nunca é bom pegar um negativo); se v[k + 1] é positivo, então a melhor soma para k é v[k] + v[k + 1], logo v[k] += v[k + 1] e zeramos v[k + 1] (pois ele já foi utilizado).
keepDependencies
Seja j o número da coluna atual, dizemos que ela está reajustada com as dependencias quando um dado item P[i][j] com i em 0..j é o seu valor original acrescido de P[i - 1][j - 1], isto é, o elemento superior à esquerda. Obviamente se j = 0, nada deve ser feito, pois P[i][-1] não é definido.
bestSum
CB: Um elemento, neste caso a melhor soma é ele mesmo. Retorne ele e fim.
HI: Dada uma pilha P de números represetados em uma matriz com n - 1 colunas (n > 1) respeitando as regras de escolha, sabemos encontrar a melhor soma para ela.
PI: Dada uma pilha P com n colunas e n linhas, retiramos a primeira coluna C. Primeiramente mantemos as dependencias (com keepDependencies) com a coluna anterior para a coluna C e encontramos a melhor solução para esta coluna (que pelo maxLinha sabemos fazer) e isso nos dá que na posição P[i][i] temos a melhor escolha para as bolas abaixo e não só isso, temos também as dependências certas para aquela coluna, isto é, aquelas que tem números negativos os mantem, já que não são boas de serem escolhidas, mas futuramente podem ser no reajuste das dependências.
Além, sabemos que todas as dependências são mantidas, mesmo que keepDependencies não some para cada bola todos acima dela, pois se uma determinada bola for escolhida, então todas acima dela também o foram (isto é garantido pelo maxLinha) e as bolas acima já tomaram os valores das demais necessárias às bolas inferiores.
Por HI sabemos calcular o melhor valor da pilha com n - 1 colunas, isto é, sem C. Logo, nossa solução é o maior entre o topo atual e o melhor para a pilha menor.
*/

int T[MAX][MAX], n = 0;

inline int max(int a, int b){
  return a > b ? a : b;
}

void maxLinha(int i, int j){
  if(i == n - 1)
    return;
  
  maxLinha(i + 1, j);
  
  if(T[i + 1][j] > 0){
    T[i][j] += T[i + 1][j];
    T[i + 1][j] = 0;
  }
}

void keepDependencies(int c){
  if(!c)
    return;
    
  int i = 0;
  
  for(i = c; i < n; i++)
    T[i][c] += T[i - 1][c - 1];
}

int bestSum(int c){ 
  keepDependencies(c);
  maxLinha(c, c);
  
  if(c == n - 1)
    return T[c][c];
  
  return max(T[c][c], bestSum(c + 1));
}

int main(){
  int i = 0, j = 0;
  
  while(1){
    scanf("%d", &n);
    getchar();
    
    if(!n)
      break;
    
    for(i = 0; i < n; i++)
      for(j = 0; j <= i; j++){
        scanf("%d", &T[i][j]);
        getchar();
      }
      
    printf("%d\n", max(bestSum(0), 0));
  }

  return 0;
}