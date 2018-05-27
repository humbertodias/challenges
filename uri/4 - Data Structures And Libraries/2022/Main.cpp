#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <iomanip>
 
using namespace std;
typedef struct{
    string presente;
    double valor;
    int preferencia;
}lista;
 
bool ordena(lista a, lista b){
    if(a.preferencia == b.preferencia){
            if(a.valor == b.valor){
                return a.presente < b.presente;
            }
        return a.valor < b.valor;
    }
    return a.preferencia > b.preferencia;
}
 
int main(){
    cout << fixed << setprecision(2);
    int n;
    string nome;
    while(cin >> nome >> n){
    cin.get();
    lista prnt[101];
    for(int i=0; i<n; i++){
        getline(cin,prnt[i].presente);
        cin >> prnt[i].valor;
        cin >> prnt[i].preferencia;
        cin.get();
    }
    sort(prnt, prnt+n, ordena);
    for(int i=0; i<n; i++){
        if(i==0){
            cout << "Lista de " << nome << endl;
        }
        cout << prnt[i].presente << " - R$" << prnt[i].valor << endl;
    }
        cout << endl;
    }
    return 0;
}