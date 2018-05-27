#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
 
int graph[4009][4009];
 
int minDistance( int dist[], int sptSet[], int V ) {
   int min = INT_MAX, min_index, v;
 
   for ( v = 0; v < V; v++ )
     if ( sptSet[ v ] == 0 && dist[ v ] <= min )
         min = dist[ v ], min_index = v;
 
   return min_index;
}
 
int dijkstra( int src, int dstn, int V ) {
     int dist[ V ];
     int sptSet[ V ];
     int i, count, v;
 
     for ( i = 0; i < V; i++ )
        dist[ i ] = INT_MAX, sptSet[ i ] = 0;
 
     dist[src] = 0;
 
     for ( count = 0; count < V-1; count++ ) {
       int u = minDistance ( dist, sptSet, V );
       sptSet[ u ] = 1;
 
       for ( v = 0; v < V; v++ )
         if ( !sptSet[ v ] && graph[ u ][ v ] && dist[ u ] != INT_MAX && dist[ u ]+graph[ u ][ v ] < dist[ v ] )
            dist[ v ] = dist[ u ] + graph[ u ][ v ];
     }
 
     return ( dist[dstn] );
}
 
typedef struct TN {
    char nome[9999];
    int id;
} TN;
 
TN t[4009];
 
int main ( int argc, char *argv[] ) {
    int P, L, i, h1, h2, source, destiny, half, tam, result1, result2, z;
    char P1[9999], P2[9999];
 
    tam = 3;
    z = 3;
    t[0].id = 0;
    strcpy ( t[0].nome, "Entrada" );
    t[1].id = 1;
    strcpy ( t[1].nome, "Saida" );
    t[2].id = 2;
    strcpy ( t[2].nome, "*" );
    memset ( graph, 0, sizeof( graph ) );
    scanf ( "%d %d", &P, &L );
    while ( L-- ) {
        scanf ( "%s %s", P1, P2 );
        int flag1 = 0;
        int flag2 = 0;
 
        for ( i=0; i<tam; i++ ) {
            if ( !strcmp(t[i].nome, P1) ) {
                h1 = t[i].id;
                flag1=1;
            }
            if ( !strcmp(t[i].nome, P2)) {
                 h2 = t[i].id;
                flag2 = 1;
            }
            if ( flag1 == 1 && flag2 == 1 ) break;
        }
        if ( flag1 == 0 ) {
            strcpy ( t[tam].nome, P1 );
            t[tam].id = z;
            h1 = z;
            tam++, z++;
        }
        if ( flag2 == 0 ) {
            strcpy ( t[tam].nome, P2 );
            t[tam].id = z;
            h2 = z;
            tam++, z++;
        }
        graph[h1][h2] = 1;
        graph[h2][h1] = 1;
    }
 
    result1 = dijkstra( 0, 2, tam );
    result2 = dijkstra( 2, 1, tam );
    int r = result1 + result2;
    printf ( "%d\n", r );
 
    return 0;
}