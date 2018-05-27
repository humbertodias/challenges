#include <cstdio>
#include <cstring>


#define MAX 300100
 
using namespace std;
 
char N[MAX], X[MAX];
 
bool Solve() {
    int Aux = 0;
    for (int i = 0; X[i] != '\0'; i++) {
        if (X[i] == N[Aux]) {
            int Cont = i;
            while (N[Aux] == X[Cont]) {
                Aux++, Cont++;
            }
            if (Aux == strlen(N)) return true;
            Aux = 0;
        }
    }
    return false;
}
 
int main(void) {
 
    int Inst = 0;
    while (scanf("%s", &N), N[0] != '0') {
        scanf("%s", &X);
        if (Inst == 0) Inst++;
        else putchar('\n');
        printf("Instancia %d\n", Inst++);
        printf((Solve() ? "verdadeira\n" : "falsa\n"));
    }
 
    return 0;
}
