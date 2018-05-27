#include <iostream>
#include <cstdio>
using namespace std;

int main(){

long double W1, W2, R, acumulacao=0.0;
int qtd=0;


while(cin >> W1 >> W2 >>R ){
    long double esq, dir;
    long double media;

    esq = W1*(1+ R/30);
    dir = W2*(1+ R/30);

    media = (esq+dir)/2;
    acumulacao+=media;

    if(W1!=0 && W2 !=0 && R!=0){
        qtd++;
        if(media>=1 && media < 13){
            cout << "Nao vai da nao" << endl;
        }
        if(media>=13 && media <14){
            cout << "E 13" << endl;
        }
        if(media>=14 && media <40){
            cout << "Bora, hora do show! BIIR!" << endl;
         }
        if(media>=40 && media <=60){
            cout << "Ta saindo da jaula o monstro!" << endl;
        }
        if(media>60){
            cout << "AQUI E BODYBUILDER!!" << endl;
        }

    }

    if(W1==W2 && W2==R && R==0){
        if((acumulacao/qtd)>40){
           printf("\nAqui nois constroi fibra rapaz! Nao e agua com musculo!\n");
            return 0;
        }
        return 0;

    }
}



}
