#include<stdio.h>
#include<string.h>
 
double graph[101][101], w;
int n, m, a, b, i, j, k;
 
void floydwarshall ( ) {
    for( k = 0; k < n; k++ )
        for(i = 0; i < n; i++ ) {
            if(i == k) continue;
            for( j = 0; j < n; j++ ){
                if( j == k || j == i ) continue;
                if(graph[i][k] * graph[k][j] > graph[i][j] && graph[i][k] && graph[k][j])
                    graph[i][j] = graph[i][k] * graph[k][j];
            }
        }
}

int main ( ) {
    while( 1 ){
        scanf("%d",&n);
        if ( n == 0 ) return 0;
        scanf("%d",&m);
 
        memset(graph, 0.0, sizeof(graph));
        for(i = 0; i < m; ++i){
            scanf( "%d %d %lf", &a, &b, &w );
            graph[a - 1][b - 1] = graph[b - 1][a - 1] = 0.01 * w;
        }
        floydwarshall( );
        printf ( "%.6lf percent\n", graph[0][n - 1] * 100 );
    }
}