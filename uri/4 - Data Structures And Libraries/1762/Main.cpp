#include <iostream>
#include <map>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath> 
using namespace std;
 
int N, X;
double Vlr, TAM, S = 0;
char Code[256];
 
map <string, double> MAP, F;
 
int main(){
 
    scanf("%d", &N);
    while(N--){
        scanf("%d", &X);
        for (int i = 0; i < X; i++) {
            getchar();
            gets(Code);
            scanf("%lf", &Vlr);
            MAP[Code] = Vlr;
            F[Code] = 1;
        }
        scanf("%lf", &TAM);
        while(1) {
            getchar();
            gets(Code);
            scanf("%d", &X);
            if(strcmp(Code, "-") == 0 && !X)
                break;
            if(F[Code])
                S += X * MAP[Code];
            else {
                printf("NAO LISTADO: ");
                puts(Code);
            }
        }
        printf("Peso total: %.2lf kg\n", S);
        printf("Numero de trenos: %.lf\n\n", ceil(S/TAM));
        MAP.clear(); F.clear(); S = 0;
    }
    return 0;
}