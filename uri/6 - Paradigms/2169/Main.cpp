#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <list>
#include <utility>

#define INF 100000000

using namespace std;

bool ordena(const pair<unsigned long long int, unsigned long long int> &a, const pair<unsigned long long int, unsigned long long int> &b){
    return a.first > b.first;
}

int main(){

    unsigned long long int a;
    while(cin >> a){
        vector<pair<unsigned long long int, unsigned long long int> > vet;
        string al;
        unsigned long long int b;
        for(unsigned long long int i = 0; i < a; i++){
            cin >> al >> b;
            if(al == "HANDGUN" || al == "MATILDA"){
                vet.push_back(make_pair(20, b));
            } else if(al == "RED9" || al == "BLACKTAIL"){
                vet.push_back(make_pair(35, b));
            } else if(al == "HANDCANNON"){
                vet.push_back(make_pair(600, b));
            } else if(al == "STRIKER" || al == "RIFLE"){
                vet.push_back(make_pair(120, b));
            } else if(al == "TMP"){
                vet.push_back(make_pair(12, b));
            }
        }

        unsigned long long int total = 0;

        cin >> a;
        for(unsigned long long int i = 0; i < a; i++){
            cin >> al >> b;
            if(al == "GANADOS"){
                total += 500 * b;
            } else if(al == "COBRAS"){
                total += 400 * b;
            } else if(al == "ZEALOT"){
                total += 750 * b;
            } else if(al == "COLMILLOS"){
                total += 600 * b;
            } else if(al == "GARRADOR"){
                total += 1250 * b;
            } else if(al == "LASPLAGAS"){
                total += 1000 * b;
            } else if(al == "GATLINGMAN"){
                total += 1500 * b;
            } else if(al == "REGENERATOR"){
                total += 2500 * b;
            } else if(al == "ELGIGANTE"){
                total += 5000 * b;
            } else if(al == "DR.SALVADOR"){
                total += 3500 * b;
            }
        }

        unsigned long long int maximo;
        cin >> maximo;

        sort(vet.begin(), vet.end(), ordena);

        int p = 0;

        unsigned long long int pontos = 0;

        while(maximo > 0 && p < vet.size()){
            if(vet[p].second <= maximo){
                pontos += vet[p].first * vet[p].second;
                maximo -= vet[p].second;
            } else {
                pontos += vet[p].first * maximo;
                maximo = 0;
            }
            p++;
        }

        if(pontos >= total){
            cout << "Missao completada com sucesso" << endl;
        } else {
            cout << "You Are Dead" << endl;
        } cout << endl;

    }

    return 0;
}