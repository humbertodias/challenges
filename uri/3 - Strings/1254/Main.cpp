#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
  string tag, n, texto, taux;
  bool t = false;

  while( cin >> tag ) {
    cin >> n;
    cin.ignore();
    
    getline( cin, texto );

    for( int i=0; i<texto.size(); i++ ) {
      if( texto[i] == '<' ) t = true;
      if( t ) {
        for( int j=i+1, k; texto[j] != '>'; j++, i++ )
          if( tolower( texto[j] ) == tolower( tag[0] ) ) {
            for( k=1; k<tag.size(); k++ )
              if( tolower( texto[j+k] ) != tolower( tag[k] ) )
                break;
            
            if( k == tag.size() )
              texto.replace( j, tag.size(), n );
          }

        t = false;
      }
    }
    cout << texto << endl;
  }

  return 0;
}