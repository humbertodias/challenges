#include <iostream>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;
 
long long int inicios[30];
 
struct Trie{
    bool esFinal;
    map<char, Trie*> children;
    long long int nodosHijos;
 
    Trie(){
        esFinal = false;
        children.clear();
        nodosHijos = 0;
    }
 
    void insertaPalabra(int index, string &word){
        if( index == word.length() ) return;
        if( children.count( word[index] ) == 0 )
            children[ word[index] ] = new Trie;
        children[ word[index] ]->insertaPalabra(index + 1, word);
    }
 
    long long int cuentaInicios(int profundidad){
        for( auto i : children ){
            if( profundidad >= 1 )
                inicios[ i.first - 'a' ]++;
            nodosHijos += i.second->cuentaInicios(profundidad + 1);
        }
        return 1 + nodosHijos;
    }
 
    long long int cuenta(int nodosSufijos, int profundidad){
        long long int ans = 0;
        if( profundidad >= 1 ) ans += nodosSufijos - 1;
        for( auto i : children ){
            if( profundidad >= 1 ) {
                //printf("Ini %d\n", inicios[i.first - 'a']);
                ans -= inicios[ i.first - 'a' ];
            }
            ans += i.second->cuenta(nodosSufijos, profundidad + 1); 
        }
        return ans;
    } 
 
};
 
int main(){
    cin.tie(0);
    std::ios_base::sync_with_stdio(false);
 
    int a, b;
    string s;
    while( cin >> a >> b ){
        if(a == 0 && b == 0) return 0;
        Trie pref, suf;
        fill(inicios, inicios + 30, 0);
        for(int i = 0; i < a; i++){
            cin >> s;
            pref.insertaPalabra(0, s);
        }
        for(int i = 0; i < b; i++){
            cin >> s;
            reverse(s.begin(), s.end());
            suf.insertaPalabra(0, s);
        }
        long long int tamanoSufijos = suf.cuentaInicios(0);
        printf("%lld\n", pref.cuenta(tamanoSufijos, 0));
    }
 
    return 0;
}