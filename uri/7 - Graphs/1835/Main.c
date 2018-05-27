#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Vetor que guardará de um vértice foi visitado na DFS.
int ans[10000];

// Representação do grafo por lista de adjacência.
typedef struct Graph {
    int id; // Número do vértice.
    struct Graph *next; // Lista de vértices adjacentes ao vértice id.
} Graph;

// Aloca uma nova lista para o id passado por parâmetro.
Graph *alloc ( int id ) {
    Graph *g = NULL;
    g = ( Graph * ) malloc ( sizeof ( Graph ) );
    g->id = id;
    g->next = NULL;
    return g;
}

// Insere uma nova aresta (que parte de "id" para "conec").
Graph * insrt ( Graph *g[555], int id, int conec ) {
    Graph *ne = alloc ( conec );
    Graph *aux, *aux2;
    if ( g[id] == NULL ) g[id] = ne;
    else {
        aux = g[id];
        aux2 = aux;
        while ( aux->next != NULL ) aux = aux->next;
        aux->next = ne;
    }
    return g[id];
}

// Busca em profundidade.
void dfs ( Graph *g[555], int start, int total ) {
    int stck[5555], visited[555]; //Pilha, Marcados de vértices visitados
    int stck_size = 0, pop; // Tamanho da pilha, auxiliar que guarda um elemento desempilhado.

  // Inicializa os dois vetores com zero.
    memset ( visited, 0, sizeof( visited ) );
    memset ( stck, 0, sizeof( stck ) );

  // Empilha todos os elementos na lista de adjacência com o id "start".
    Graph * aux = g[start];

    while ( aux != NULL ) {
        stck_size ++;
        stck[ stck_size ] = aux->id;
        aux = aux->next;
    }
  
  // Marca "start" como visitado.

    visited[ start ] = 1;
    int i;

    while ( stck_size > 0 ) {
    // Desempilha um elemento.
        pop = stck[ stck_size ];
        stck_size--; // Diminui o tamanho da pilha.

    // Caso o vértice desempilhado não tenha sido visitado...
        if ( visited[ pop ] == 0 ) {
      // Adiciona todos os seus vértices adjacentes na pilha caso não tenham sido visitados.
            Graph *aux2 = g[ pop ];
            while ( aux2 != NULL ) {
                if ( visited[ aux2->id ] == 0 ) {
                    stck_size ++;
                    stck[ stck_size ] = aux2->id;
                }
                aux2 = aux2->next;
            }
      // Marca como visitado (vetor "visited") E como alcançável (vetor "ans").
            visited[ pop ] = 1;
            ans[pop] = 1;
        }
    }
}

int main ( ) {

    int t, n, m, x, y, i, k;

    scanf ( "%d", &t ); // Número de casos de teste.
    for ( k = 1; k <= t; k++ ) {
    // Inicialização do grafo e vetor resposta.
        Graph *g[555] = { };
        memset ( ans, 0, sizeof ( ans ) );

        scanf ( "%d", &n ); // Número de vértices
        scanf ( "%d", &m ); // Número de arestas.

        for ( i = 1; i <= m; i++ ) {
            scanf ( "%d %d", &x, &y );
      // Insere uma aresta que parte de x para y e de y para x.
            g[y] = insrt ( g, y, x );
            g[x] = insrt ( g, x, y );
        }
    // Imprime o "caso" conforme o enunciado do problema.
        printf ( "Caso #%d: ", k );

    // Resultado. Inicia com -1 pois a primeira DFS não conta.
        int totalsets = -1;
        for ( i = 1; i <= n; i++ ) {
      // Caso um vértice não tenha sido alcançado ainda, chamar outra DFS a partir dele.
            if ( ans[i] == 0 ) {
                dfs ( g, i, n );
        // Como não foi alcançado anteriormente significa que precisa de uma estrada para este vértice.
                totalsets++;
            }
        }
        if ( totalsets >= 1 ) printf ( "ainda falta(m) %d estrada(s)", totalsets );
        else printf ( "a promessa foi cumprida" );
        puts ( "" );
    }
    return 0;
}