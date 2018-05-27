#include <cstdio>
#include <cmath>
#include <cstring>

int main()
{
    int tst, i;
    scanf("%d", &tst);
    while(tst--)
    {
        long long int num, dcml = 0ll, tmp;
        char str[65];
        scanf("%s %lld", str, &num);
        for(i=0; str[i]; i++)
        {
            if(str[i]=='O')
                dcml += ceil(pow(2, i));
        }
        int lnth = strlen(str);
        tmp = ceil(pow(2, lnth));
        dcml += num;
        dcml = dcml % tmp;
        tmp = dcml;
        while(tmp)
        {
            if(tmp%2ll) printf("O");
            else printf("X");
            tmp /= 2ll;
        }
        tmp = log2(dcml) + 1ll;
        for(i=lnth - tmp; i>=1; i--)
            printf("X");
        printf("\n");
    }
    return 0;
}