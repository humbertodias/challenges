#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int k, m, n;
 
int fav[500];
int qt[500];
int atual[500];
int fim[500];

int favoritas(){
    int res = 0;
    for(char c='a'; c<='z'; c++)
        res += qt[c] * fav[ atual[c] ];
    return res;
}


int main(){
    cin>>k>>m>>n;
    memset(fav, 0, sizeof fav);
    string s;
    cin >> s;
    for(int i=0; i<k; i++) 
        fav[s[i]]=1;
    
    cin >> s;

    for(int i=0; i<m; i++) 
        qt[s[i]]++;

    for(char c='a'; c<='z'; c++)
        fim[c] = atual[c]=c;

    int ans = favoritas();

    while(n--){
        char o1[5], o2[5];
        scanf("%s %s", o1, o2);
        for(char c='a'; c<='z'; c++)
            if(atual[c] == o1[0]){
                atual[c]=o2[0];
            }else{
                if(atual[c]==o2[0])
                    atual[c]=o1[0];
            }

            if(favoritas() > ans){
                ans = favoritas();
                for(char c='a'; c<='z'; c++)
                    fim[c]=atual[c];
            }
    }

    printf("%d\n", ans);
    for(int i=0; i<m;i++) printf("%c", fim[s[i]]);
    printf("\n");

}
