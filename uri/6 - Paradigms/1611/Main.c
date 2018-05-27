#include<stdio.h>
#include<stdlib.h>
 
int compare ( const void * a, const void * b ) {
  return ( * ( int* ) b - * ( int* ) a );
}
 
int main ( ) {
    int t, n, c, m, i, j, ans;
    int floors[100000];
 
    scanf ( "%d", &t );
 
    while ( t-- ) {
 
        scanf ( "%d %d %d", &n, &c, &m );
        for ( i = 0; i < m; i++ )
            scanf ( "%d", &floors[i] );
        qsort ( floors, m, sizeof(int), compare );
        ans = 0;
 
        for ( i = 0; i < m; i += c )
            ans += floors[i] * 2;
 
        printf ( "%d\n", ans );
    }
 
    return 0;
}