#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
using namespace std;
 
 
typedef struct tarefas
{
    long long int v, t;
} Tarefas;
 
int comp_freq_v(const void* a, const void* b)
{
    Tarefas ca = *(Tarefas*)a;
    Tarefas cb = *(Tarefas*)b;
    if (ca.v > cb.v) return -1;
    else return 1;
 
}
 
 
int comp_freq_t(const void* a, const void* b)
{
    Tarefas ca = *(Tarefas*)a;
    Tarefas cb = *(Tarefas*)b;
    if (ca.v == cb.v)
    {
        if(ca.t > cb.t)return 1;
        else return -1;
    }
    return -1;
}
 
 
int main(int argc, char *argv[])
{
    int n, h;
    while(cin >> n >> h)
    {
        Tarefas t[1002];
        long int perda = 0, controle[1002], cont = 0, maior = 0;
        memset(controle, 0, sizeof(controle));
 
        for(int i = 0; i <= 1001; i++)
        {
            t[i].v = 0;
            t[i].t = 0;
             
        }
 
        for(int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            if(y > maior) maior = y;
            perda += x;
            t[i].v = x;
            t[i].t = y;
 
        }
        qsort(t, n, sizeof(Tarefas), comp_freq_v);
        qsort(t, n, sizeof(Tarefas), comp_freq_t);


        int j = 0;
        int aux = h, m = 0;
        cont = maior;
        while(aux > 0 && j <= n)
        {
            int n2 = t[j].t;

            if(controle[n2] < n2 && t[j].t <= h && cont > 0)
            {
                perda -= t[j].v;
 
                aux--;
                controle[t[j].t]++;
                cont--;
            }
            if(controle[n2] == n2 && n2 > m)
            {
                for(; m <= n2; m++)
                {
                    controle[m] = m;
 
                }
                m = n2;
            }
 
            j++;
 
        }
        cout << perda << endl;
 
    }
    return 0;
}