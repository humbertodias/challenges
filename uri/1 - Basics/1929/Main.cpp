#include <iostream>
#include <string>
#include <cstring>

using namespace std;
 
int main() {
 
    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
     string linha;
     getline (cin,linha);

     char chr[linha.size()];
     linha.copy(chr, linha.size());

     int a = atoi(strtok(chr, " "));
     int b = atoi(strtok(NULL, " "));
     int c = atoi(strtok(NULL, " "));
     int d = atoi(strtok(NULL, " "));

     int tenta1 = (abs(b-c) < a && a < (b+c)) || (abs(a-c) < b && b < (a+c)) || (abs(a-b) < c && c < (a+b)); // a b c
     int tenta2 = (abs(c-d) < b && b < (c+d)) || (abs(b-d) < c && c < (b+d)) || (abs(b-c) < d && d < (b+c)); // b c d
     int tenta3 = (abs(c-d) < a && a < (c+d)) || (abs(a-d) < c && c < (a+d)) || (abs(a-c) < d && d < (a+c)); // a c d
     int tenta4 = (abs(b-d) < a && a < (b+d)) || (abs(a-d) < b && b < (a+d)) || (abs(a-b) < d && d < (a+b)); // a b d

     cout << ((tenta1 || tenta2 || tenta3 || tenta4) ? 'S' : 'N') << endl;

     return 0;
}
