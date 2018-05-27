#include <cstdio>
#include <cstring>
using namespace std;

int tipo(char x){
    int tipo;
    if(x<='9' && x>='0')
        tipo=1;
    else if ((x>='a' && x<='z') || (x>='A' && x<='Z'))
        tipo=1;
    else if(x==')')
        tipo=2;
    else if(x=='+' || x=='-' || x=='*' || x=='/'|| x=='>' || x=='<' || x=='=' || x=='#' || x=='|' || x  =='.' || x=='^')
        tipo=3;
   else if (x=='(')
        tipo=4;
   else
        tipo=-1;
    return tipo;
}
int prioridade(char x){
    int prio;
    if(x=='^')
        prio=6;
    else if(x=='+' || x=='-')
        prio=4;
    else if(x=='*' || x=='/')
        prio=5;
    else if(x=='>' || x=='<' || x=='=' || x=='#')
        prio=3;
    else if(x=='.')
        prio=2;
    else if(x=='|')
        prio=1;
    else
        prio=0;
    return prio;
}
int main(){
    char a[100010],atu,pilha[100010],res[100010];
    int tamanho,tipos[100010],ok,tam,r;
    while(scanf(" %s",&a)!=EOF){
        ok=-1;
        r=0;
        tamanho = strlen(a);
        a[tamanho]=')';
        a[++tamanho]='\0';
        tam=-1;
        getchar();
        for(int i=-1;i<tamanho;i++){
 
            if(i!=-1){
                atu=a[i];
            }
            else{
                atu='(';
            }

            if(i>=0){
                tipos[i]=tipo(atu);

                if(i>=0){
                    int ant;
                    if(i==0)
                         ant=4;
                    else
                         ant=tipos[i-1];
                    int pos=tipos[i];
                    if((pos==ant && pos!=4 && pos!=2)){

                        ok=1;
                        break;
                    }
                    if(pos==4 && (ant==2 || ant==1)){

                        ok=1;
                        break;
                    }
                    if((pos==2 && (ant==4))){

                        ok=1;
                        break;
                    }
                }
 
                if(tipos[i]==-1){

                    ok=2;
                    break;
                }
                if(tipos[i]==3){

                    while(prioridade(pilha[tam])>=prioridade(atu) && pilha[tam]!='(' && pilha[tam]!=')'){
                        res[r++]=pilha[tam--];
                    }
                    pilha[++tam]=atu;
                }
                if(tipos[i]==1){

                    res[r++]=atu;
                }
            }
            if(atu=='('){

                pilha[++tam]=atu;
            }
            if(atu==')'){

                while(pilha[tam]!='('){
                    res[r++]=pilha[tam--];
                }
                tam--;
            }
            pilha[tam+1]='\0';

        }
 

        res[r]='\0';
        if(ok==-1  && tam==-1){
            printf("%s",res);
        }
        else if(ok==2){
            printf("Lexical Error!");
        }
        else if(ok==1 || tam!=-1){
            printf("Syntax Error!");
        }
        printf("\n");
    }
}