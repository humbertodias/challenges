#include <iostream>
#include <string>
using namespace std;

struct No{
  char valor;
  No* esq;
  No* dir;
  No(){}
  No(char valor, No* esq=NULL, No* dir=NULL):
    valor(valor), esq(esq), dir(dir) {}
};

No* raiz;
bool esp;

void prefixa(No* no){
  if(!no) 
    return;

  if(esp)
    cout << " ";

  esp = 1;

  cout << no->valor;
  prefixa(no->esq);
  prefixa(no->dir); 
}

void infixa(No* no){
  if(!no) 
    return;

  infixa(no->esq);

  if(esp)
    cout << " ";

  esp = 1;

  cout << no->valor;
  infixa(no->dir);
}

void posfixa(No* no){
  if(!no) 
    return;

  posfixa(no->esq);
  posfixa(no->dir);
  
  if(esp)
    cout << " ";
  
  esp = 1;

  cout << no->valor;
}

void insere(char c){
  if(raiz == NULL){
    raiz = new No(c);
    return;
  }
  No* aux = raiz;

  while(1){
    if(c > aux->valor){
      if(aux->dir == NULL){
        aux->dir = new No(c);
        return;
      }
      aux = aux->dir;
    }
    if(c < aux->valor){
      if(aux->esq == NULL){
        aux->esq = new No(c);
        return;
      }
      aux = aux->esq;
    }
  }
}

bool procura(char c){
  No* aux = raiz;

  while(aux){
    if(aux->valor == c)
      return true;

    if(c > aux->valor)
      aux = aux->dir;
    else
      aux = aux->esq;
  }

  return false;
}

int main(){
  string op;
  raiz = NULL;

  while(getline(cin,op)){
    if(op.size() == 3){
      if(op[0] == 'P'){
        if(procura(op[2]))
          cout << op[2] << " existe" << endl;
        else
          cout << op[2] << " nao existe" << endl;
      }

      if(op[0] == 'I'){
        insere(op[2]);
      }
      continue;
    }

    esp = 0;

    if(op == "INFIXA")
      infixa(raiz);

    if(op == "PREFIXA")
      prefixa(raiz);
    
    if(op == "POSFIXA")
      posfixa(raiz);

    cout << endl;
  }
}