#include <cstdio>
#include <vector>
#include <set>
#include <cstring>
#include <iostream>
#include <map>
using namespace std; 
 
int main()
{
    map<string, int> mapa;
    map<pair<int, int> , string> campeao;
    string nome, op;
    int pr=1;
    while(cin >> nome && nome != "FIM")
    {
        cin >> op;
        if(mapa.find(nome) == mapa.end())
        {
            if(op == "YES")
            {
                campeao[make_pair(-nome.size(), pr)] = nome, pr++;
                mapa[nome] = 1;
            }
            else mapa[nome] = 2;
        }
    }
    map<string, int>::iterator it;
    map<pair<int, int>, string>::iterator it2 = campeao.begin();
    for(int i = 1; i <= 2; i++)
        for(it = mapa.begin(); it != mapa.end(); it++)
            if(it->second == i)
                cout << it->first << endl;
    cout << endl << "Amigo do Habay:\n";
    cout << it2->second << "\n";
 
    return 0;
}