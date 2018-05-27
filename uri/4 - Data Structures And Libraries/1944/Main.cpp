#include <cstdio>
#include <cstring>
 
int main ( ) {
    int n, ans = 0, tail = 4;
    char arr[9999] = { 'F', 'A', 'C', 'E' };
    char read1[2], read2[2], read3[2], read4[2];
    scanf ( "%d", &n );
    while ( n-- ) {
        scanf ( "%s %s %s %s", read1, read2, read3, read4 );
        if ( read1[0] == arr[tail-1] && read2[0] == arr[tail-2] && read3[0] == arr[tail-3] && read4[0] == arr[tail-4] ) {
            tail -= 4;
            if ( tail == 0 ) {
                arr[0] = 'F', arr[1] = 'A', arr[2] = 'C', arr[3] = 'E';
                tail = 4;
            }
            ans++;
        }
        else {
            arr[tail]=read1[0], tail++;
            arr[tail]=read2[0], tail++;
            arr[tail]=read3[0], tail++;
            arr[tail]=read4[0], tail++;
        }
    }
    printf ( "%d\n", ans );
     
    return 0;
}