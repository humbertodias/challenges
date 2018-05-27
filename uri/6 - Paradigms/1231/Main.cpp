#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <utility>

#define MAXTAM 40
#define MAXN 20

using namespace std;


map <pair<string,int>,int > mapa;


int n[2];

char v[2][MAXN][MAXTAM+1];


int vai(char s1[], char s2[], int p)
{
    int i, j;
    
    if (strcmp(s1,s2) == 0)
        return 1;
    
    for (i=0; s1[i] && s2[i] && s1[i]==s2[i]; i++);


    if (s1[i] && s2[i]) // diferentes no i-esimo caracter
        return 0;

    if (!s2[i]) // s2 substring de s1
    {
        if (mapa.find(make_pair((string)&s1[i], 0))==mapa.end())
        {
            mapa[make_pair((string)&s1[i], 0)] = 1;
            for (j=0; j<n[1]; j++)
            {
                if (vai(&s1[i], v[1][j], p+1))
                    return 1;
            }
        }
    }
    else
    {
        if (mapa.find(make_pair((string)&s2[i], 1))==mapa.end())
        {
            mapa[make_pair((string)&s2[i], 1)] = 1;
            for (j=0; j<n[0]; j++)
            {
                if (vai(v[0][j],&s2[i], p+1))
                    return 1;
            }
        }
    }
    
    return 0;
}


int checa()
{
    int i, j;
    
    for (i=0; i < n[0]; i++)
    {
        for (j=0; j< n[1]; j++)
        {
            if (vai(v[0][i], v[1][j], 0) == 1)
                return 1;
        }
    }
    return 0;
}

int main()
{
    int i, k;
    while (scanf("%d %d", &n[0], &n[1]) == 2)
    {
        for (k = 0; k <= 1; k++)
            for (i = 0; i<n[k]; i++)
            {
                scanf("%s", v[k][i]);
            }
        
        mapa.clear();
        if (checa())
            printf("S\n");
        else {
            printf("N\n");
        }

    }
    return 0;
}