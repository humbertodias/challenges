#include <iostream>
#include <cstdio>

using namespace std;

int fibMod(long long n, const int M)
{
    if ( n <= 0 ) return 0;

    long long a, b, c, d, aux;
    a = 1, b = 0;
    c = 0, d = 1;
    --n;

    while ( n > 0 )
    {
        if ( n&1 )
        {
            aux = ( (d*b) + (c*a) )%M;
            b = ( d*(b+a) + (c*b) )%M;
            a = aux;
        }

        aux = ( c*c + d*d )%M;
        d = ( d * (2*c + d) )%M;
        c = aux;

        n = n/2;
    }

    return (a + b)%M;
}

int main()
{
    long long n;
    int b, result, caseNo = 0;

    while ( cin >> n >> b )
    {   
        if (n == 0 && b == 0) break;
        result = ( (2 * fibMod(n+1, b)) - 1 + b ) % b;
        cout << "Case " << (++caseNo) << ": " << n << " " << b << " " << result << endl;
    }

    return 0;
}