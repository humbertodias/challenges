#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <bitset>
#include <climits>
#include <list>
#include <functional>
#include <cmath>
#include <ctime>
#include <utility>
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define inf 1e9
#define linf 1e18
#define EPS 1e-5
#define PI acos(-1)
#define pii pair<int,int>
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()
#define ms(x,val) memset(x, val, sizeof(x))
#define pb(x) push_back(x)
#define make_unique(x) sort(ALL(x)) ; x.erase( unique(ALL(x)), x.end()) ;
 
const int bfsz = 1 << 16;
char bf[bfsz + 5];
int rsz = 0;
int ptr = 0;
char gc()
{
    if (rsz <= 0)
    {
        ptr = 0;
        rsz = fread(bf, 1, bfsz, stdin);
        if (rsz <= 0) return EOF;
    } --rsz;
    return bf[ptr++];
}
void ga(char &c)
{
    c = EOF;
    while (!isalpha(c)) c = gc();
}
int gs(char s[])
{
    int l = 0;
    char c = gc();
    while (isspace(c)) c = gc();
    while (c != EOF && !isspace(c))
    {
        s[l++] = c;
        c = gc();
    }
    s[l] = '\0';
    return l;
}
template<class T> bool gi(T &v)
{
    v = 0;
    char c = gc();
    while (c != EOF && c != '-' && !isdigit(c)) c = gc();
    if (c == EOF) return false;
    bool neg = c == '-';
    if (neg) c = gc();
    while (isdigit(c))
    {
        v = v * 10 + c - '0';
        c = gc();
    }
    if (neg) v = -v;
    return true;
}
 
long long gcd(long long x, long long y)
{
    return y == 0 ? x : gcd(y, x % y);
}
int toInt(char xx)
{
    return xx - '0';
}
 
int exitInput = 0;
int ntest = 1, itest = 1 ;
 
void read() ;
void solve() ;
 
int main()
{
 
    ios_base::sync_with_stdio(0) ;
 
 
    for (itest = 1; itest <= ntest ; ++itest)
        for (itest = 1; ; ++itest)
        {
            read();
            if (exitInput)
            {
                break;
            }

            solve();
 
        }
 
    return 0;
}
 
 
/*** IMPLEMENTATION ***/
const ll Mod = 1e8;
const int maxn = 100 + 5 ;
 
int n, m ;
pii a[maxn] ;
int f[2*maxn][2*maxn] ;
vector<int> rrh ;
int hasZero, hasN ;
 
int dp(int L, int R)
{
    int &ref = f[L][R] ;
    if(ref != -1)
    {
        return ref ;
    }
    ref = 0 ;
    int i, lo, hi ;
 
    for(i = 0; i < m; ++i)
    {
        lo = a[i].fi ; hi = a[i].se ;
 
        if(lo < L && L <= hi && hi < R)
        {
            if(lo == 1)
            {
                ref += 1 ;
            }
            else
            {
                ref += dp(lo,min(hi,L)) ;
            }
        }
        ref %= Mod ;
    }
    return ref ;
}
 
void read()
{
#define endread { exitInput = 1 ; return ; }
    rrh.clear();
    cin >> n >> m ; if(n + m == 0) endread ;
 
    hasZero = hasN = 0 ;
 
    rrh.pb(n);
    for(int i = 0; i < m; ++i)
    {
        cin >> a[i].fi >> a[i].se ;
        if(a[i].fi == 0) hasZero = 1 ;
        if(a[i].se == n) hasN = 1 ;
 
        rrh.pb(a[i].fi); rrh.pb(a[i].se);
    }
    make_unique(rrh);
    n = 1 + lower_bound(ALL(rrh),n)-rrh.begin();
    for(int i = 0; i < m; ++i)
    {
        a[i].fi = 1 + lower_bound(ALL(rrh),a[i].fi)-rrh.begin();
        a[i].se = 1 + lower_bound(ALL(rrh),a[i].se)-rrh.begin();
    }
 
 
}
 
void solve()
{
    if(!hasZero || !hasN)
    {
        puts("0");
        return ;
    }
    ms(f,-1) ;
    int res = 0, i, lo, hi ;
    for(i = 0; i < m; ++i)
    {
        lo = a[i].fi ; hi = a[i].se ;
        if(lo == 1)
        {
            f[lo][hi] = 1;
        }
    }
    for(i = 0; i < m; ++i)
    {
        lo = a[i].fi ; hi = a[i].se ;
        if(hi == n)
        {
            res += dp(lo,hi) ;
            res %= Mod ;
        }
    }
    printf("%d\n",res) ;
}