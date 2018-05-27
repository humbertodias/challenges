#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

#define ll long long int

using namespace std;

char m[32], s[32];
ll C;

bool letra(char c) {
    return 'A' <= c and c <= 'Z';
}

ll velho(char *s) {
    return (s[6]-'0')+
        10*(s[5]-'0')+
        100*(s[4]-'0')+
        1000*(s[3]-'0')+
    10000*(s[2]-'A')+
    10000*26*(s[1]-'A')+
    10000*26*26*(s[0]-'A');
}

ll indx(char c) {
    ll r = (c-'A');
    if (c >= 'A') r--;
    if (c >= 'C') r--;
    if (c >= 'I') r--;
    if (c >= 'M') r--;
    if (c >= 'P') r--;
    return r;
}

ll novo(char *s) {
    return (s[6]-'0') +
    10*(s[5]-'0') +
    100*indx(s[4])+
    100*21*indx(s[3])+
    100*21*21*indx(s[2])+
    100*21*21*21*indx(s[1])+
    100*21*21*21*21*indx(s[0]);
}

int main() {

    while(scanf("%s %s %lld",m,s,&C) and (s[0]!='*')) {
        // valido?
        bool ok=false;
        if (!letra(s[3]) and !letra(s[4]))
            ok=true;
        else if (letra(s[3]) and letra(s[4]) and
          s[0] != 'A' and s[0] != 'C' and s[0] != 'M' and s[0] !='I' and s[0] != 'P' and
          s[1] != 'A' and s[1] != 'C' and s[1] != 'M' and s[1] !='I' and s[1] != 'P' and
          s[2] != 'A' and s[2] != 'C' and s[2] != 'M' and s[2] !='I' and s[2] != 'P' and
          s[3] != 'A' and s[3] != 'C' and s[3] != 'M' and s[3] !='I' and s[3] != 'P' and
          s[4] != 'A' and s[4] != 'C' and s[4] != 'M' and s[4] !='I' and s[4] != 'P')
            ok=true;
        else
            ok=false;
        if (!ok) {
            printf("N\n");
            continue;
        }
        // valores
        ll v1, v2;
        if (!letra(m[3])) v1 = velho(m); else v1 = novo(m)+velho((char *)"ZZZ9999")+1;
        if (!letra(s[3])) v2 = velho(s); else v2 = novo(s)+velho((char *)"ZZZ9999")+1;
        if (v2 > v1 and v2 <= v1+C)
            printf("Y\n");
        else
            printf("N\n");
    }

    return 0;
}