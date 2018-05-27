#include <iostream>
//#include <ctype>
using namespace std;

struct no {
   char c;
   no *esq, *dir;
   no( char c ) { this->c = c, esq = NULL, dir = NULL; }
};

int main() {
   string exp;
   no *topo = NULL;
   no *prev;

   cin >> exp;
   for( int i=0; i<exp.size(); i++ ) {
      no *novo = new no( exp[i] );
      
      if( topo == NULL ) {
         topo = novo;
         continue;
      }

      if( isalnum( exp[i] ) ) {
         while(  )
      } else {
         switch( exp ) {
            case '+':
               while(  ) {
                  
               }
            case '-':
            case '*':
            case '/':
         }
      }
   }

   return 0;
}