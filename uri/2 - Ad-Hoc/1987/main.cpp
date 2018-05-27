#include <iostream>

using namespace std;

int main()
{
   string m;
   long n;

   while (cin >> n >> m )
   {
      unsigned long long sum = 0;

      //O arquivo de entrada conterá dois números, n (1< n <10) indicando o número de algarismos de m, (1< m < 1000000000).
      // if(stol(m) < 1 || stol(m) > 1000000000)
      //    continue;

      // if(n < 1 || n>10) continue;

      // if(n != m.length()){
      //    continue;
      // }

      for (long i = 0; i < n; ++i)
         sum += m[i] - '0';

      if (sum % 3 == 0) cout << sum << " sim\n";
      else cout << sum << " nao\n";
   }

   return 0;
}