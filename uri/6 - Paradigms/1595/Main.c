#include<stdio.h>
#include<stdlib.h>


/**********************************************************************
* Função de comparar utilizada no qsort.
**********************************************************************/
int compare ( const void * a, const void * b ) {
  return ( * ( int* ) a - * ( int* ) b );
}
 
/**********************************************************************
* Função principal.
**********************************************************************/
int main ( int argc, char *argv[] ) {
    int t, s, i, c;
    double r, ans;
    int v[100001];
 
    scanf ( "%d", &t );
 
    while ( t-- ) {
        scanf ( "%d %d %lf", &s, &c, &r );
        for ( i = 0; i < s; i++ )
            scanf ( "%d", &v[i] );
    
    /* Ordena de forma crescente a velocidade em cada parte do 
     * percurso.*/
        qsort ( v, s, sizeof(int), compare );
        ans = 0.0;

    /* Para otimizar o tempo, deve-se correr nas "c" partes do
     * percurso com a menor velocidade e andar nas outras. */
        for ( i = 0; i < c; i++ )
            ans += 1.0 / ( (double)v[i]*1.0 + r*1.0 );
 
        for ( i = c; i < s; i++ )
            ans += 1.0 / (double)v[i]*1.0;
 
        printf ( "%.2lf\n", ans );
    }
 
    return 0;
}