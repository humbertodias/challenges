#include <iostream>
#include <algorithm>
using namespace std;

string op( string expressao ) {
    int i, subexp = 0;
    bool inter = false, uniao = false, difer = false;
    string grupo = "", aux = "", sub = "";

    while( expressao.size() > 0 ) {
        i = 0;
        switch( expressao[i] ) {
            case '(': if( subexp ) sub += expressao[i];
                      subexp++;
            break;
            case ')': subexp--;
                      if( !subexp ) {
                          sub = op( sub );
                          sub = "{" + sub + "}";
                      }
                      else sub += expressao[i];
            break;
            case '{': if( subexp ) sub += expressao[i];
            break;
            case '}': if( subexp ) sub += expressao[i];
                      else if( inter ) {
                          inter = false;
                          grupo = aux;
                          aux.clear();
                      } else if( uniao ) uniao = false;
                      else if( difer ) difer = false;
            break;
            case '*': if( subexp ) sub += expressao[i];
                      else inter = true;
            break;
            case '+': if( subexp ) sub += expressao[i];
                      else uniao = true;
            break;
            case '-': if( subexp ) sub += expressao[i];
                      else difer = true;
            break;
            default: if( subexp ) sub += expressao[i];
                     else if( inter ) {
                         size_t found = grupo.find( expressao[i] );
                         if( found != string::npos )
                             aux += expressao[i];
                     } else if( uniao ) {
                         size_t found = grupo.find( expressao[i] );
                         if( found == string::npos )
                             grupo += expressao[i];
                     } else if( difer ) {
                         size_t found = grupo.find( expressao[i] );
                         if( found != string::npos )
                             grupo.erase( grupo.begin()+found );
                     } else
                         grupo += expressao[i];
            break;
        }
        expressao.erase( expressao.begin() );
        if( !subexp ) {
            expressao = sub + expressao;
            sub.clear();
        }
    }

    return grupo;
}

int main() {
    int subexp;
    bool p;
    string expressao, grupo;

    while( cin >> expressao ) {
        for( int i=0; i<expressao.size(); i++ )
            if( expressao[i] == '*' ) {
                subexp = 0, p = true;
                for( int j=i-1; j>=0 && p; j-- )
                    switch( expressao[j] ) {
                        case ')': subexp++;
                        break;
                        case '(': subexp--;
                                  if( !subexp ) expressao.insert( expressao.begin()+j, '(' ), p = false;
                        break;
                        case '{': if( !subexp ) expressao.insert( expressao.begin()+j, '(' ), p = false;
                        break;
                    }
                i++, subexp = 0, p = true;
                for( int j=i+1; j<expressao.size() && p; j++ )
                    switch( expressao[j] ) {
                        case '(': subexp++;
                        break;
                        case ')': subexp--;
                                  if( !subexp ) expressao.insert( expressao.begin()+j+1, ')' ), p = false;
                        break;
                        case '}': if( !subexp ) expressao.insert( expressao.begin()+j+1, ')' ), p = false;
                        break;
                    }
            }
        grupo = op( expressao );
        sort( grupo.begin(), grupo.end() );
        cout << "{" + grupo + "}" << endl;
    }

    return 0;
}