#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <iomanip>
#include <map>
#include <vector>
#include <sstream>
 
#define MAX 50
 
using namespace std;
 
vector <int> V[MAX], F;
vector <int>::iterator it;
map <string, int> MAP;
map <string, int>::iterator _it;
 
int N, X, C = 1;
string IN, Final = "";
bool Enter = true;
 
void NEW() {
    F.clear();
    for (int i = 0; i < 26; i++) F.push_back(i);
    for (int l = 0; l < 26; l++) {
        V[l].clear();
        for (int i = 0; i < 26; i++) {
            V[l].push_back(i);
        }
    }
}
 
void RUN(int E) {
    for (int i = 0; i < 26; i++) {
        it = V[i].begin() + F[E];
        int X = *it;
        V[i].erase(V[i].begin() + F[E]);
        V[i].push_back(X);
    }
    it = F.begin() + E;
    int X = *it;
    F.erase(F.begin() + E);
    F.push_back(X);
}
 
void ENGINE(int E) {
    if (E >= 26) {
        Final += " ";
    }
    else {
        Final += 'A' + V[F[E]][F[E]];
        RUN(E);
    }
}
 
void PRINT() {
    if (Enter) Enter = false;
    else printf("\n");
    printf("LISTA #%d:\n", C++);
    for (_it = MAP.begin(); _it != MAP.end(); _it++) {
        for (int i = 0; i < _it->second; i++) {
            cout << _it->first << endl;
        }
    }
}
 
int main(void) {
 
    while (scanf("%d", &N) != EOF) {
        NEW(), MAP.clear(), cin.get();
        for (int i = 0; i < N; i++) {
            getline(cin, IN);
            stringstream Eng(IN);
            while (Eng >> X) {
                ENGINE((X - 1));
            }
            MAP[Final]++, Final = "";
        }
        PRINT();
    }
    return 0;
}