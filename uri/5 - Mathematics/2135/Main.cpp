#include <cstdio>

int main(){
  int n, inst = 1;
  while( scanf( "%i", &n ) != EOF ){
     int soma = 0;
     int valor, achei = 0, termo;
     while( n-- != 0 ){
        scanf( "%i", &valor );
        if( valor == soma && !achei ){
           achei = 1;
           termo = valor;
        }
        soma += valor;
     }
     printf( "Instancia %i\n", inst++ );
     if( achei ){
        printf( "%i\n\n", termo );
     }
     else{
        printf( "nao achei\n\n" );
     }
  }
  return 0;
}