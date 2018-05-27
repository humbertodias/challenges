#include <iostream>
#include <vector>
#define FOR(i, a, b) for(int i = a; i < b; ++i)
using namespace std;

int r, c;

int di[] = {-1, -1, 0, 0, 1, 1};
int dj[] = {0, 1, -1, 1, -1, 0};

bool comp[10001];
int comps;

void init_comp()
{
    FOR(i, 0, 10001)
    {
        comp[i] = false;
    }
    comps = 1;
}


char grid[101][101];
int result[101][101];//cor
bool visitado[101][101];//visitado
int component[101][101];//componentes

void dfs1(int a, int b)//dfs so para determinar os componentes
{
    visitado[a][b] = true;
    component[a][b] = comps;
    FOR(k, 0, 6)
    {
        int posi = a + di[k];
        int posj = b + dj[k];
        if(posi >= 0 && posi < r && posj >= 0 && posj < c && grid[posi][posj] != '.')
        {
            if(!visitado[posi][posj])
            {
                if(result[posi][posj] == result[a][b])
                {
                    comp[component[a][b]] = true;
                }
                else
                    result[posi][posj] = 1 - result[a][b];
                dfs1(posi, posj);
            }
            else if(result[a][b] == result[posi][posj])
            {
                comp[component[a][b]] = true;
            }
            
        }
    }
}

void dfs2(int a, int b)//O PROBLEMA ESTA AQUI
{
    visitado[a][b] = true;
    FOR(k, 0, 6)
    {
        int posi = a + di[k];
        int posj = b + dj[k];
        if(posi >= 0 && posi < r && posj >= 0 && posj < c && grid[posi][posj] != '.')
        {
            if(!visitado[posi][posj])
            {
                if(result[posi][posj] == result[a][b])
                {
                    comp[component[a][b]] = true;
                }
                else
                    result[posi][posj] = 1 - result[a][b];
                dfs2(posi, posj);
            }
            else if(result[a][b] == result[posi][posj])
            {
                comp[component[a][b]] = true;
            }
        }
    }
}

void print_graph(int t, int v)
{
    FOR(i, 0, t)
    {
        FOR(j, 0, v)
        {
            cout << component[i][j] << " ";
        }
        cout << endl;
    }
}

void init_visitado()
{
    FOR(i, 0, 101)
    {
        FOR(j, 0, 101)
        {
            visitado[i][j] = false;
        }
    }
}

void init_component()
{
    FOR(i, 0, 101)
    {
        FOR(j, 0, 101)
        {
            component[i][j] = 0;
        }
    }
}

void init_result()
{
    FOR(i, 0, 101)
    {
        FOR(j, 0, 101)
        {
            result[i][j] = -1;
        }
    }
}

int main()
{
    char cs;
    cin >> r >> c;
    while(r != 0 || c != 0)
    {
        init_comp();
        init_result();
        FOR(i, 0, r)
        {
            FOR(j, 0, c)
            {
                cin >> cs;
                grid[i][j] = cs;
                if(cs == 'I')
                {
                    result[i][j] = 1;
                }
                else result[i][j] = 2000;
                visitado[i][j] = false;
            }
        }

        init_component();
        init_visitado();
        FOR(i, 0, r)
        {
            FOR(j, 0, c)
            {
                if(!visitado[i][j] && grid[i][j] == 'I')
                {
                    dfs1(i, j);
                    comps++;
                }
            }
        }

        
        cout << endl;
        FOR(i, 0, r)
        {
            FOR(j, 0, c)
            {
                if(grid[i][j] == '.')
                    cout << '.';
                else if(comp[component[i][j]])
                {
                    cout << 'B';
                }
                else if(result[i][j] == 1)
                {
                    cout << '(';
                }
                else if(result[i][j] == 0)
                {
                    cout << ')';
                }
                else cout << 'F';
            }
            cout << endl;
        }
        cin >> r >> c;
    }
    return 0;
}