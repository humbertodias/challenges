#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <cstring>

#define inf 0x3f3f3f3f
using namespace std;

map<string, vector< pair<string, int> > >grafo;
map<string, int>dist;
set<string>vist;

bool a1 = true, b2 = true;

int dijkstra(string orig, string dest)
{
    priority_queue<pair<string, int>, vector<pair<string, int> >, greater<pair<string, int> > >fila;

    dist[orig] = 0;
    fila.push(make_pair(orig, dist[orig]));
    while (!fila.empty())
    {
        pair<string, int> x = fila.top();
        string u = x.first;
        fila.pop();
        if (vist.find(u) == vist.end())
        {
            vist.insert(u);
            for (int i = 0; i < grafo[u].size(); i++)
            {
                string v = grafo[u][i].first;
                int custo = grafo[u][i].second;
                if (dist[v] > (dist[u] + custo))
                {
                    dist[v] = dist[u] + custo;
                    fila.push(make_pair(v, dist[v]));
                }
            }
        }
    }
    return dist[dest];
}

string formata(int time)
{
    if (time == 0)
        return "00";
    else
    {
        char vet[10];
        sprintf(vet, "%d", time);
        string x = vet;
        return x;
    }
}

int main()
{
    char vet[1000];
    int t, tmp, aux, custo;
    string a, b, x;
    while (cin >> tmp >> t >> aux, tmp and t and aux)
    {
        getchar();
        while (t--)
        {
            cin >> a >> b;
            getchar();
            cin >> custo;
            grafo[a].push_back(make_pair(b, custo));
            dist[a] = inf;
            dist[b] = inf;
        }
        int caminho = dijkstra("varzea", "alto");
        if (caminho != inf)
        {
            int soma = 1700 + tmp;


            int hora = 17;
            int minutos = 0;



            if (soma <= 1730)
            {

                caminho += 30;
                if(caminho >= 7*60){
                    caminho -= 420;
                    hora = 0;
                }

                hora += (int) caminho / 60;

                minutos = caminho % 60;
                cout << formata(hora) << ":" << formata(minutos) <<endl;
                if(hora  == 17 or (hora ==18 and minutos == 0))
                {

                    cout << "Nao ira se atrasar" << endl;
                }
                else
                    cout << "Ira se atrasar" << endl;
            }
            else
            {
                caminho += 50;
                if(caminho >= 7*60){
                    caminho -= 420;
                    hora = 0;
                }

                hora += (int) caminho / 60;

                minutos = caminho % 60;
                cout << formata(hora) << ":" << formata(minutos) <<endl;

                if(hora  == 17 or (hora ==18 and minutos == 0))
                    cout << "Nao ira se atrasar" << endl;
                else
                    cout << "Ira se atrasar" << endl;

            }
        }
        strcpy(vet,"");
        grafo.clear();
        vist.clear();
        dist.clear();
        x.clear();
    }
}