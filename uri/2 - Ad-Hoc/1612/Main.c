#include <stdio.h>
#include <math.h>

int main()
{
    int n, r,i;
    double x;

    scanf("%i", &n);

    for (i = 0; i < n; ++i)
    {
        scanf("%lf", &x);
        r = ceil(x/2);
        printf("%i\n", r);
    }

    return 0;
}