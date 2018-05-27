#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <cstdio>
#include <sstream>

using namespace std;
 
int main ()
{
    vector<string> dias;
    dias.push_back("DOM");
    dias.push_back("SEG");
    dias.push_back("TER");
    dias.push_back("QUA");
    dias.push_back("QUI");
    dias.push_back("SEX");
    dias.push_back("SAB");
    vector<string> mes;
    mes.push_back("JAN");
    mes.push_back("FEV");
    mes.push_back("MAR");
    mes.push_back("ABR");
    mes.push_back("MAI");
    mes.push_back("JUN");
    mes.push_back("JUL");
    mes.push_back("AGO");
    mes.push_back("SET");
    mes.push_back("OUT");
    mes.push_back("NOV");
    mes.push_back("DEZ");
 
 
    string entrada;
    int cont = 1;
    while(cin >> entrada) {
        if(entrada == "FIM") break;
        string aux = "";
        stringstream ss;
        struct tm * ptm, x = {0};
        time_t tempo;
        // time(&tempo);
        // ptm = localtime ( &tempo );
 
        //dia da semana
        aux+=entrada[0];
        aux+=entrada[1];
        aux+=entrada[2];
        for(int i=0; i<dias.size(); i++){
             if(aux==dias[i]) x.tm_wday=i;
         }
 
        //dia do mes
        aux="";
        aux += entrada[4];
        aux += entrada[5];
        ss << aux;
        ss >> x.tm_mday;
        ss.clear();
 
        //mes
        aux = "";
        aux += entrada[6];
        aux += entrada[7];
        aux += entrada[8];
        if(aux == "JAN") x.tm_mon = 0;
        if(aux == "FEV") x.tm_mon = 1;
        if(aux == "MAR") x.tm_mon = 2;
        if(aux == "ABR") x.tm_mon = 3;
        if(aux == "MAI") x.tm_mon = 4;
        if(aux == "JUN") x.tm_mon = 5;
        if(aux == "JUL") x.tm_mon = 6;
        if(aux == "AGO") x.tm_mon = 7;
        if(aux == "SET") x.tm_mon = 8;
        if(aux == "OUT") x.tm_mon = 9;
        if(aux == "NOV") x.tm_mon = 10;
        if(aux == "DEZ") x.tm_mon = 11;
 
        //ano
        aux = "";
        aux += entrada[9];
        aux += entrada[10];
        aux += entrada[11];
        aux += entrada[12];
        ss << aux;
        ss >> x.tm_year;
        ss.clear();
        x.tm_year -= 1900;
 
        //hr
        aux = "";
        aux += entrada[14];
        aux += entrada[15];
        ss << aux;
        ss >> x.tm_hour;
        ss.clear();
 
        //min
        aux = "";
        aux += entrada[17];
        aux += entrada[18];
        ss << aux;
        ss >> x.tm_min;
        ss.clear();
 
        //seg
        aux = "";
        aux += entrada[20];
        aux += entrada[21];
        ss << aux;
        ss >> x.tm_sec;
        ss.clear();
 
        int momento;
        printf("Previsao #%d\n", cont++);
        for(int i = 0; i < 5; i++) {
            scanf("%d", &momento);
            //printf("- %d\n", momento);
 
            x.tm_isdst=1;
 
            x.tm_sec+=momento;
 
            tempo = mktime(&x);//transforma em time_t
 
            x.tm_sec-=momento;
 
            ptm = localtime ( &tempo );//tranforma em struct tm
 
            cout << dias[ptm->tm_wday];
 
            printf(",%02d", ptm->tm_mday);
            cout << mes[ptm->tm_mon];
            printf("%d:", ptm->tm_year+1900);
            printf("%02d:", ptm->tm_hour);
            printf("%02d:", ptm->tm_min);
            printf("%02d\n", ptm->tm_sec);
 
        }
 
    }
 
 
 
    return 0;
}