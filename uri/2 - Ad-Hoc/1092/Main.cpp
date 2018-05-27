#include <iostream>
#include <cstring>

#define rep(i, s, t) for(int i=s; i<t; i++)

using namespace std;

void the_case(int n, int m)
{
    int in[n][m];
    int a[2][m][m];
    int t=0; 
    int ans = 0;
    memset(a, 0, sizeof(a));
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cin >> in[i][j];
        }
    }
    rep(i, 0, n)
    {
        memset(a[t], 0, sizeof(a[t]));
        for (int j1=0; j1<m; j1++) 
        {
            if (i==0 || in[i][j1] > in[i-1][j1])
                a[t][j1][j1] = a[1-t][j1][j1] + 1;
            else a[t][j1][j1] = 1;
            if(ans<a[t][j1][j1]) ans = a[t][j1][j1];
            rep(j2, j1+1, m)
            {
                if(in[i][j2]>in[i][j2-1]) // j2==0
                {
                    if(i==0 || in[i][j1]>in[i-1][j2])
                        a[t][j1][j2] = a[1-t][j1][j2]+j2-j1+1;
                    else
                        a[t][j1][j2] = j2-j1+1;
                    if(ans<a[t][j1][j2]) ans = a[t][j1][j2];
                }
                else break;
            }
        }
        t = 1-t;
    }
    cout << ans << endl;
}

int main()
{
    int n,m;
    while(true)
    {
        cin >> n >> m;
        if(n==0 && m==0) break;
        else the_case(n,m);
    }
    return 0;
}