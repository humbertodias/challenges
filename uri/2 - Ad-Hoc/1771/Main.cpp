#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
#define watch(x) cout << #x << " is " << x << endl
 
typedef vector<int> vi;
typedef vector<vi> vvi;
 
int main(void) {
    int _0;
 
    // Para cada caso de teste.
    while (scanf("%d", &_0) == 1) {
        vvi v(5, vi(5));
 
        // Leitura.
        v[0][0] = _0;
 
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == 0 and j == 0) continue;
                else if (i == 2 and j == 2) v[i][j] = 99;
                else scanf("%d", &v[i][j]);
            }
        }
 
        // Processamento.
        bool ok = true;
        bool reciclavel = true;
 
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == 2 and j == 2) continue;
 
                // Se o valor estiver fora do range.
                if (v[j][i] < 1 + (i * 15) or v[j][i] > 15 + (i * 15)) {
                    ok = false;
 
                    int col = (v[j][i] - 1) / 15;
                    bool found = false;
 
                    // Procuro na coluna correta de v[j][i] se posso trocar.
                    for (int k = 0; k < 5; k++) {
                        if (k == 2 and col == 2) continue;
 
                        if (v[k][col] >= 1 + (i * 15) and v[k][col] <= 15 + (i * 15)) {
                            swap(v[k][col], v[j][i]);
                            found = true;
                            break;
                        }
                    }
 
                    if (!found) reciclavel = false;
                }
            }
        }
 
        // Saída.
        if (ok) puts("OK");
        else if (reciclavel) puts("RECICLAVEL");
        else puts("DESCARTAVEL");
    }
 
    return 0;
}