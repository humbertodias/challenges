#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
 
using namespace std;
 
int verifica=0;
int cara=0;
void Preenche(){
    if(!verifica) printf("\n");
    for(int i=0; i<80; i++) printf("-");
    printf("\n");
    verifica=1;
    cara=0;
}
 
int main(){
    char entrada[600];
 
    while(fgets(entrada,600,stdin)){
       stringstream ss;
       string palavra;
       verifica=0;
       ss << entrada;
       while(ss >> palavra){
 
            if(palavra.compare("<br>")==0){
                printf("\n");
                verifica=1;
                cara=0;
 
            }
            else if(palavra.compare("<hr>")==0){
                Preenche();
            }else{
                if((palavra.size() + cara) == 80){
                    cout << palavra << endl;
                    //printf("\n");
                    cara=0;
                }else if((palavra.size() + cara) > 80){
                    printf("\n");
                    cout << palavra;
                    cara=0;
                }else{
                    if(cara!=0) printf(" ");
                    cout << palavra;
                }
                cara += palavra.size()+1;
                verifica=0;
            }
       }
    }
    printf("\n");
 
    return 0;
}