#include <iostream>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

map<int,string>mapaNumeros;
string resp;
string resp2;

void preencheMapa(){
    mapaNumeros.insert(pair<int,string>(0,"zero"));
    mapaNumeros.insert(pair<int,string>(1,"um"));
    mapaNumeros.insert(pair<int,string>(2,"dois"));
    mapaNumeros.insert(pair<int,string>(3,"tres"));
    mapaNumeros.insert(pair<int,string>(4,"quatro"));
    mapaNumeros.insert(pair<int,string>(5,"cinco"));
    mapaNumeros.insert(pair<int,string>(6,"seis"));
    mapaNumeros.insert(pair<int,string>(7,"sete"));
    mapaNumeros.insert(pair<int,string>(8,"oito"));
    mapaNumeros.insert(pair<int,string>(9,"nove"));
    mapaNumeros.insert(pair<int,string>(10,"dez"));
    mapaNumeros.insert(pair<int,string>(11,"onze"));
    mapaNumeros.insert(pair<int,string>(12,"doze"));
    mapaNumeros.insert(pair<int,string>(13,"treze"));
    mapaNumeros.insert(pair<int,string>(14,"quatorze"));
    mapaNumeros.insert(pair<int,string>(15,"quinze"));
    mapaNumeros.insert(pair<int,string>(16,"dezesseis"));
    mapaNumeros.insert(pair<int,string>(17,"dezessete"));
    mapaNumeros.insert(pair<int,string>(18,"dezoito"));
    mapaNumeros.insert(pair<int,string>(19,"dezenove"));
    mapaNumeros.insert(pair<int,string>(20,"vinte"));
    mapaNumeros.insert(pair<int,string>(30,"trinta"));
    mapaNumeros.insert(pair<int,string>(40,"quarenta"));
    mapaNumeros.insert(pair<int,string>(50,"cinquenta"));
    mapaNumeros.insert(pair<int,string>(60,"sessenta"));
    mapaNumeros.insert(pair<int,string>(70,"setenta"));
    mapaNumeros.insert(pair<int,string>(80,"oitenta"));
    mapaNumeros.insert(pair<int,string>(90,"noventa"));
    mapaNumeros.insert(pair<int,string>(100,"cem"));
    mapaNumeros.insert(pair<int,string>(101,"cento"));
    mapaNumeros.insert(pair<int,string>(200,"duzentos"));
    mapaNumeros.insert(pair<int,string>(300,"trezentos"));
    mapaNumeros.insert(pair<int,string>(400,"quatrocentos"));
    mapaNumeros.insert(pair<int,string>(500,"quinhentos"));
    mapaNumeros.insert(pair<int,string>(600,"seiscentos"));
    mapaNumeros.insert(pair<int,string>(700,"setecentos"));
    mapaNumeros.insert(pair<int,string>(800,"oitocentos"));
    mapaNumeros.insert(pair<int,string>(900,"novecentos"));
    mapaNumeros.insert(pair<int,string>(1000,"mil"));
}

string retornaDois(string resp,string numero){

        if(numero[0]=='2'){
            resp += mapaNumeros.find(20)->second;
        }

        if(numero[0]=='3'){
            resp += mapaNumeros.find(30)->second;
        }

        if(numero[0]=='4'){
            resp += mapaNumeros.find(40)->second;
        }

        if(numero[0]=='5'){
            resp += mapaNumeros.find(50)->second;
        }

        if(numero[0]=='6'){
            resp += mapaNumeros.find(60)->second;
        }

        if(numero[0]=='7'){
            resp += mapaNumeros.find(70)->second;
        }

        if(numero[0]=='8'){
            resp += mapaNumeros.find(80)->second;
        }

        if(numero[0]=='9'){
            resp += mapaNumeros.find(90)->second;
        }

        /***** pos 1 */

        if(numero[0]!='0' && numero[1]!='0'){
            resp += " e ";
        }

        if(numero[1]=='1'){
            resp += mapaNumeros.find(1)->second;
        }

        if(numero[1]=='2'){
            resp += mapaNumeros.find(2)->second;
        }

        if(numero[1]=='3'){
            resp += mapaNumeros.find(3)->second;
        }

        if(numero[1]=='4'){
            resp += mapaNumeros.find(4)->second;
        }

        if(numero[1]=='5'){
            resp += mapaNumeros.find(5)->second;
        }

        if(numero[1]=='6'){
            resp += mapaNumeros.find(6)->second;
        }

        if(numero[1]=='7'){
            resp += mapaNumeros.find(7)->second;
        }

        if(numero[1]=='8'){
            resp += mapaNumeros.find(8)->second;
        }

        if(numero[1]=='9'){
            resp += mapaNumeros.find(9)->second;
        }

        return resp;
    }

string retornaTres(string resp,string numero){

        if((numero[0]=='1') && (numero[1]=='0' && numero[2]=='0')){
            resp += mapaNumeros.find(100)->second;
        }

        if((numero[0]=='1') && (numero[1]!='0' || numero[2]!='0')){
            resp += mapaNumeros.find(101)->second;
        }

        if(numero[0]=='2'){

            resp += mapaNumeros.find(200)->second;
        }

        if(numero[0]=='3'){

            resp += mapaNumeros.find(300)->second;
        }

        if(numero[0]=='4'){
            resp += mapaNumeros.find(400)->second;
        }

        if(numero[0]=='5'){
            resp += mapaNumeros.find(500)->second;
        }

        if(numero[0]=='6'){

            resp += mapaNumeros.find(600)->second;
        }

        if(numero[0]=='7'){

            resp += mapaNumeros.find(700)->second;
        }

        if(numero[0]=='8'){

            resp += mapaNumeros.find(800)->second;
        }

        if(numero[0]=='9'){

            resp += mapaNumeros.find(900)->second;
        }

        if((numero[1]!='0' && numero[2]!='0') ||
           (numero[1]=='0' && numero[2]!='0') ||
           (numero[1]!='0' && numero[2]=='0'))
        {
            // if(numero[0]=='0')
                resp += " e ";
            // else{
            //     resp += " e ";
            // }
        }

        return resp;
    }

void paraTresChars(string resp,string numero){

    resp = "";
    resp2 = "";

    resp2 += (numero[1]);
    resp2 += (numero[2]);

        char t[numero.size()];
        strcpy(t,resp2.c_str());

        if(atoi(t) <= 20 && atoi(t) > 0){
            resp2 = mapaNumeros.find(atoi(t))->second;
        }

        if(atoi(t) >= 21){
            resp2 = retornaDois(resp,t);
        }

    resp = retornaTres(resp,numero);

    if(resp2!="00"){
        resp+=resp2;
    }

    if(numero.size()>3 && resp.size()>10)
      printf("%s ",resp.c_str());
    else
      printf("%s",resp.c_str());
    // printf("%s[%d][%d]",resp.c_str(), numero.size(), resp.size());
}

int main()
{
    preencheMapa();
    int valor;

    while(cin>>valor){

        resp.clear();
        resp2.clear();

        char numero[120000];
        sprintf(numero,"%d",valor);

        if(strlen(numero)==1){
            printf("%s",mapaNumeros.find(valor)->second.c_str());
        }

        if(strlen(numero)==2 && valor <= 20){
            printf("%s",mapaNumeros.find(valor)->second.c_str());
        }

        if(strlen(numero)==2 && valor >= 21){
            resp = retornaDois(resp,numero);
            printf("%s",resp.c_str());
        }

        if(strlen(numero)==3){
            paraTresChars(resp,numero);
        }

        if(strlen(numero)==4){

            char aux[10000];
            aux[0] = numero[1];
            aux[1] = numero[2];
            aux[2] = numero[3];

            resp = aux;

            if(numero[0]!='1'){

                if(numero[1]!= '0' && numero[2]-'0' == 0 && numero[3]-'0' == 0)
                    printf("%s mil e ",mapaNumeros.find(numero[0]-'0')->second.c_str());

                else
                    printf("%s mil",mapaNumeros.find(numero[0]-'0')->second.c_str());
            }else{

                if(numero[1]!= '0' && numero[2]-'0' == 0 && numero[3]-'0' == 0)
                    printf("mil e %s",mapaNumeros.find(numero[0]-'0')->second.c_str());

                else{
                    string x = mapaNumeros.find(numero[0]-'0')->second.c_str();
                    printf("mil");

                    if(numero[1]!= '0' && numero[2]-'0' != 0)
                    printf(" ");
                }
            }

            paraTresChars(resp,aux);
        }

        if(strlen(numero)==5){

                char aux[10000];
                aux[0] = numero[2];
                aux[1] = numero[3];
                aux[2] = numero[4];

                resp = aux;

                char aux2[10000];

                aux2[0] = numero[0];
                aux2[1] = numero[1];

                int num = atoi(aux2);

                if(num <= 20){

                    if(aux[0]=='0' && aux[1]=='0' && aux[2]=='0'){
                        printf("%s mil",mapaNumeros.find(num)->second.c_str());
                    }else
                        printf("%s mil",mapaNumeros.find(num)->second.c_str());
                }

                if(num >= 21){
                    resp2 = retornaDois(resp2,aux2);

                    if(aux[0]=='0' && aux[1]=='0' && aux[2]=='0'){
                        printf("%s mil",resp2.c_str());
                    }else
                        printf("%s mil",resp2.c_str());
                }

                if(aux[0]!='0' && aux[1]=='0' && aux[2]=='0'){
                    printf(" e ");
                }
                paraTresChars(resp,aux);
            }

        if(strlen(numero)==6){
                char aux[10000];
                aux[0] = numero[3];
                aux[1] = numero[4];
                aux[2] = numero[5];

                resp = aux;

                char aux2[10000];

                aux2[0] = numero[0];
                aux2[1] = numero[1];
                aux2[2] = numero[2];

                resp2 = aux2;

                paraTresChars(resp2,aux2);

                if(aux[0]!='0' && aux[1]=='0' && aux[2]=='0'){

                    printf(" mil e ");
                }else{

                    if(aux[0]=='0' && aux[1]=='0' && aux[2]=='0'){
                        printf(" mil");
                    }else
                        printf(" mil ");
                }

                paraTresChars(resp,aux);
            }

        printf("\n");
    }
    return 0;
}
