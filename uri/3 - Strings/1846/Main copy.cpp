#include <iostream>
#include <string>
using namespace std;
int n1[36] = { 900000, 800000, 700000, 600000, 500000, 400000, 300000, 200000,
    100000, 90000, 80000, 70000, 60000, 50000, 40000, 30000, 20000, 19000,
    18000, 17000, 16000, 15000, 14000, 13000, 12000, 11000, 10000, 9000,
    8000, 7000, 6000, 5000, 4000, 3000, 2000, 1000 };
int n2[36] = { 900, 800, 700, 600, 500, 400, 300, 200, 100, 90, 80, 70, 60, 50,
    40, 30, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3,
    2, 1 };
string n3[36] = { "novecentos", "oitocentos", "setecentos", "seiscentos",
    "quinhentos", "quatrocentos", "trezentos", "duzentos", "cem", "noventa",
    "oitenta", "setenta", "sessenta", "cinquenta", "quarenta", "trinta",
    "vinte", "dezenove", "dezoito", "dezessete", "dezesseis", "quinze",
    "quatorze", "treze", "doze", "onze", "dez", "nove", "oito", "sete",
    "seis", "cinco", "quatro", "tres", "dois", "um" };

int main() {
  ios::sync_with_stdio(false);
  int num;
  while (cin >> num) {
    string str;
    if (num == 0)
      str = "zero";
    else {
      if (num >= 2000) {
        int k = 0;
        while (k < 36) {
          if (num >= n1[k]) {
            if (k == 8) {
              num -= n1[k];
              if (num >= 1000)
                str += "cento e ";
              else {
                str += n3[k];
                str += " mil";
                if (num > 0) {
                  str += " ";
                  if (num % 100 == 0 || num < 100)
                    str += "e ";
                }
                break;
              }
            } else {
              num -= n1[k];
              if (num == 0 && k > 30){
                str += " e ";
//                cout << n1[k] << " -- " << k;
              }
              str += n3[k];
              if (num > 1000)
                str += " e ";
              if (num < 1000) {
                str += " mil";
                if (num > 0) {
                  str += " ";
                  if (num % 100 == 0 || num < 100)
                    str += "e ";
                }
              }

            }
          }
          k++;
        }
      } else {
        if (num >= 1000) {
          num -= 1000;
          str += "mil";
          if (num > 0) {
            str += " ";
            if (num % 100 == 0 || num < 100)
              str += "e ";
          }
        }
      }
      if (num > 0) {
        int k = 0;
        while (k < 36) {
          if (num >= n2[k]) {
            if (k == 8) {
              num -= n2[k];
              if (num >= 1)
                str += "cento e ";
              else {
                str += n3[k];
                break;
              }
            } else {
              num -= n2[k];
              str += n3[k];
              if (num > 0)
                str += " e ";
            }
          }
          k++;
        }
      }
    }

    cout << str << endl;
  }
  return 0;
}