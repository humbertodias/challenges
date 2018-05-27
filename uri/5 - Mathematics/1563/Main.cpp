#include <iostream>
#include <cstdio>
using namespace std;
typedef unsigned long long int ulli;

ulli euclides_slow(ulli a, ulli b)
{
    ulli r;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

 ulli euclides_2(ulli x, ulli y) {
    while (x * y != 0) {
        if (x >= y) x = x % y;
        else y = y % x;
    }
    return (x + y);
}

ulli gcd2(ulli a, ulli b){
        if( a<0 ) a = -a;
        if( b<0 ) b = -b;
        while( b!=0 ){
            a %= b;
            if( a==0 ) return b;
            b %= a;
        }
        return a;
    }    

ulli gcd(ulli a, ulli b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

int main(int argc, char **argv)
{
    ulli n, i, mod_sum, denominator, loop_prune;

    std::ios_base::sync_with_stdio(false);
    while(cin >> n)
    {
        denominator = n * n;
        mod_sum = 0;
        loop_prune = n / 2;

        for(i = 2; i <= loop_prune; ++i)
            mod_sum += n % i;

        // from (n / 2) + 1, the remainders will form an arithmetic progression
        // this value can be calculated effortlessly using a closed formula
        ulli remainder = n % (loop_prune + 1);
        mod_sum += remainder > 1 ? ((1 + remainder) * remainder) / 2 : remainder;
        ulli divi = gcd(denominator, mod_sum);
        printf("%llu/%llu\n", mod_sum / divi, denominator / divi);
    }
    return 0;
}