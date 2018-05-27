#include <string>
#include <iostream>
#include <map>
#include <cstdio>

using namespace std;
 
int main(){
 
    char X, aux;
    while (scanf("%c", &X) != EOF) {
        if(X=='s' || X=='v' || X=='p' || X=='x' || X=='b' || X=='j' || X=='z' || X=='f') {
            if(aux != 'f' && aux != 'F') {
                printf("f");
                aux = 'f';
            }
        }
        else if(X=='S' || X=='V' || X=='P' || X=='X' || X=='B' || X=='J' || X=='Z' || X=='F') {
            if(aux != 'f' && aux != 'F') {
                printf("F");
                aux = 'F';
            }
        }
        else {
            printf("%c", X);
            aux = X;
        }
    }
    return 0;
}