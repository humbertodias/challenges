#include <iostream>  
#include <cmath>
#include <cstdio>
#include <map>
#include <string>

using namespace std;
int convert(string num)
{
  int exp = num.size() - 1, s = 0, i = 0;
  while(num[i])
  {
    s += (num[i] - 48) * pow(10, exp);
    exp--, i++;
  }
  return s;
}
int main()
{
  map<string, int> mapa;
  int n, pontos;
  string time;
  while(cin >> n && n)
  {
    mapa.clear();
    for(int i = 0; i < n; i++)
    {
      cin >> time >> pontos;
      mapa[time] = pontos; 
    }
    string time1, time2, placar, p1, p2;
    for(int i = 0; i < n/2; i++)
    {
      cin >> time1 >> placar >> time2;
      p1 = p2 = "";
      int j=0;
      while(placar[j] != '-')
        p1+=placar[j], j++;
      j+=1;
      while(j < placar.size())
        p2+=placar[j], j++;
      
      int gols1 = convert(p1);
      int gols2 = convert(p2);
      mapa[time1] += gols1*3;
      mapa[time2] += gols2*3;
      if(gols1 == gols2)
        mapa[time1]++, mapa[time2]++;
      else if(gols1 > gols2) mapa[time1]+=5;
      else mapa[time2] += 5;  
    }
    string vencedor = "";
    int pontosVencedor = 0;
    map<string, int>::iterator it;
    for(it = mapa.begin(); it != mapa.end(); it++)
    {
      if(it->second> pontosVencedor)
        pontosVencedor = it->second, vencedor = it->first;
    }
    if(vencedor == "Sport")
      cout << "O " << vencedor <<" foi o campeao com "<<pontosVencedor<<" pontos :D\n";
    else
      cout << "O Sport nao foi o campeao. O time campeao foi o "<<vencedor<<" com " <<pontosVencedor<<" pontos :(\n";
    cout << endl;
  }
  return 0;
}