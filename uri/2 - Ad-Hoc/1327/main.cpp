#include <iostream>  
#include <vector>
#include <string>
#include <cmath>

using namespace std;

#define pb push_back

vector< int > v, idr;

int main() {
  int n, c[55], menor;
  bool answer;
  string nome[25];

  while( cin >> n && n ) {
    v.clear();
    answer = false;
    for( int i=0; i<n; i++ )
      cin >> nome[i], v.pb( i );

    menor = 15;
    for( int i=1, k=1; i<=52; i++, k++ ) {
      cin >> c[i];
      menor = min( menor, c[i] );
      if( !answer && k == n ) {
        if( i == 52 ) continue;
        
        idr.clear();
        for( int j=i-n+1, id=0; j<=i; j++, id++ )
          if( c[j] == menor )
            idr.pb( id ), n--;

        if( n == 1 )
          answer = true;
        if( n == 0 )
          answer = true;
        else
          for( int j=idr.size()-1; j>=0; j-- )
            v.erase( v.begin()+idr[j] );

        k = 0;
        menor = 15;
      }
    }
    for( int i=0; i<v.size(); i++ )
        cout << nome[ v[i] ] << " ";

    cout << endl;
  }

  return 0;
}