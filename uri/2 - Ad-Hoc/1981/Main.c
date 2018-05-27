#include <stdio.h>
#include <string.h>
#define MAX 112345
#define P 100000007 // 10^8 + 7 (?)

typedef int ll;

ll fac(ll n){
    ll ret = 1;
    ll i;
    for(i = 2; i <= n; i++){
      ret *= i % P;
      ret %=P;
    }
    return ret;
}

int main(void) {
    char s[MAX];
    int quant[26];
    ll ans, acum, n;
    int i;
    while(scanf("%s", s), strcmp(s, "0")){
      memset(quant,0,sizeof(quant));
      for(i = 0; s[i]; i++){
         quant[s[i]-'a']++;
      }
      n = i;
      
      acum = 1;
      for(i = 0; i < 26; i++){
         if(quant[i] > 0){
            acum *= fac(quant[i]) % P;
            acum %= P;
         }
      }
      ans = ((fac(n) % P) / acum) %P;
        printf("%d\n", ans);
    }
    return 0;
}