#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

string infixaParaPrefixa( string inf ) {
    reverse( inf.begin(), inf.end() );
    for( int i = 0; i < inf.size(); i++ ) {
        if( inf[i] == '(' ) inf[i] = ')';
        else if( inf[i] == ')' ) inf[i] = '(';
    }
    string pref = "";
    stack<char> pilha;

    for( int i = 0; i < inf.size(); i++ )
        switch( inf[i] ) {
            case '(':
                pilha.push( inf[i] );
                break;
            case ')':
                while( !pilha.empty() && pilha.top() != '(' ) {
                    pref += pilha.top();
                    pilha.pop();
                }
                if( pilha.top() == '(' )
                    pilha.pop();
                break;
            case '+':
            case '-':
                while( !pilha.empty() && ( pilha.top() == '*' || pilha.top() == '/' ) ) {
                    pref += pilha.top();
                    pilha.pop();
                }
                pilha.push( inf[i] );
                break;
            case '*':
            case '/':
                pilha.push( inf[i] );
                break;
            default:
                pref += inf[i];
        }
    while( !pilha.empty() )
        pref += pilha.top(), pilha.pop();

    reverse( pref.begin(), pref.end() );
    return pref;
}

struct Tnode {
    char data;
    Tnode *l, *r;

    Tnode( char _data ) : data(_data) {
        l = r = NULL;
    }
};

int id;
string data_nivel[50];

Tnode* parse( string pref, int nivel ) {
    char data = pref[id++];
    Tnode *node = new Tnode( data );
    
    data_nivel[nivel] += data;

    if( data == '+' || data == '-' || data == '*' || data == '/' || data == '^' ) {
        node->l = parse( pref, nivel+1 );
        node->r = parse( pref, nivel+1 );
    }

    return node;
}

int main() {
    string in, inf, pref;
    Tnode *tree;
    bool barraN = false;

    while( getline( cin, in ) ) {
        cout << ( barraN ? "\n" : "" ), barraN = true;

        inf.clear();
        id = 0;
        for( int i = 0; i < 50; i++ )
            data_nivel[i].clear();

        stringstream ss( in );
        while( ss >> in )
            inf += in;

        pref = infixaParaPrefixa( inf );

        tree = parse( pref, 0 );

        for( int i = 0; data_nivel[i].size(); i++ )
            cout << "Nivel " << i << ": " << data_nivel[i] << endl;
    }
}