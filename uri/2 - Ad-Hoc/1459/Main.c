#include<stdio.h>
#include<stdlib.h>
 
typedef struct objects {
    int s, e; //start (ponto de início) e end (ponto do final)
} objects;
 
 
// Compara o ponto de final para ordenar o vetor
int compareend ( objects * o1, objects * o2 ) {
    const struct objects * elem1 = o1;
    const struct objects * elem2 = o2;
    if ( elem1->e < elem2->e ) return 1;
    else return -1;
}
 
// Compara o ponto de início para ordenar o vetor
int comparestart ( objects * o1, objects * o2 ) {
    const struct objects * elem1 = o1;
    const struct objects * elem2 = o2;
    if ( elem1->s > elem2->s ) return 1;
    else if ( elem1->s < elem2->s ) return -1;
    else return compareend ( o1, o2 );
    // Caso o ponto de "início" empate chama a função de comparar o ponto de "final" para desempatar
}
 
// Função que retorna o valor máximo entre dois inteiros
int max ( int a, int b ) {
    return ( a > b ) ? a : b;
}
 
// Função que retorna o valor mínimo entre dois inteiros
int min ( int a, int b ) {
    return ( a < b ) ? a : b;
}
 
// Vetor de struct
objects o[1000001];
 
int main ( ) {
    int n, i, j, k, ans, b, t;
 
    while ( scanf ( "%d", &n ) != EOF ) {
        // Lê todos os pontos de início e fim e guarda no vetor de struct
        for ( i = 0; i < n; i++ )
            scanf ( "%d %d", &o[i].s, &o[i].e );
 
        // Ordena o vetor de struct de acordo com o ponto de início
        qsort ( o, n, sizeof( objects ), ( int ( * ) ( const void *, const void * ) ) comparestart );
 
        ans = 0;
 
        for ( i = 0; i < n; i++ ) {
            // Caso o objeto i+1 possa ser capturado na mesma opção que o objeto i:
            if ( i < n-1 && o[i+1].s <= o[i].e ) {
                k = i, j = i+1;
                // Obtém o maior "início"
                b = max ( o[i].s, o[i+1].s );
                // Obtém o menor "fim"
                t = min ( o[i].e, o[i+1].e );
                ans++;
                // Com os pontos extremos em que os dois objetos podem ser capturados, procurar outros objetos que possam ser capturados dentro desses limites
                while ( i < n && j < n && o[i].e == o[j].e && o[i].s == o[j].s )
                    j++, i++;
                while ( i < n && j < n && !( ( o[j].s > t ) || ( o[j].e < b ) ) ) {
                    b = max ( o[j].s, b );
                    t = min ( o[j].e, t );
                    j++, i++;
                    while ( i < n && j < n && o[i].e == o[j].e && o[i].s == o[j].s )
                        j++, i++;
                }
            }
            else {
                // Se os objetos não puderem ser capturados na mesma foto terá que tirar duas fotos, aumentando ans (answer, resposta)
                ans++;
            }
        }
        // Imprime a resposta
        printf ( "%d", ans );
        // Meu teclado não tem contra barra zzz gambiarra alternativa
        puts ( "" );
    }
    return 0;
}