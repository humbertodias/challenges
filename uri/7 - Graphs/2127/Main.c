    #include<stdio.h>
    #include<stdlib.h>
     
    int flag[1001];  
    struct edge {
           int v1;
           int v2;
           int Peso;
        }; 
     
    struct lista {
           struct edge edge;
           struct lista* prox;
    };
    typedef struct lista Lista;
    typedef struct edge Aresta;
     
    Lista* inicializa (void)
    {
       return NULL;
    }
     
    Lista* insere (Lista* l, Aresta i)
    {
       Lista* novo = (Lista*) malloc(sizeof(Lista));
       novo->edge = i;
       novo->prox = l;
       return novo;
    }
     
     
     
    void kruskal(Lista *Caixas[3],int n){
        int sum=0,i=0;
        Lista *PAux;
        for (i=0;i<=2;i++){
            PAux = Caixas[i];
            while (PAux!=NULL){
                  if ((flag[PAux->edge.v1]==0) || (flag[PAux->edge.v2]==0)){
                     sum+= PAux->edge.Peso;
                  } 
                  PAux = PAux->prox;    
            } 
     
        }
        printf("%d\n\n",sum);
    }
     
    int main(){
        Lista *Caixas[3];
        Aresta Aresta;
        int i=0,j=0,n=0,m=0,u=0,v=0,c=0,numInst=0;
     
        while (scanf("%d %d",&n,&m) != EOF){
              Caixas[0]=inicializa();
              Caixas[1]=inicializa();
              Caixas[2]=inicializa();
              for (i=1;i<=m;i++){
                  flag[i] = 0;
              }
              for (i=1;i<=m;i++){
                  scanf("%d %d %d",&u,&v,&c);
                  Aresta.Peso = c;
                  Aresta.v1 = u;
                  Aresta.v2 = v;
                  if (c == 1235){
                     Caixas[0] = insere (Caixas[0], Aresta);
                  }else if (c == 8977){
                     Caixas[1] = insere (Caixas[1], Aresta);
                  }else if (c == 10923){
                     Caixas[2] = insere (Caixas[2], Aresta);
                  }
              }
     
              numInst++;
              printf("Instancia %d\n",numInst);
              kruskal(Caixas,n);
     
        }
        return(0);
    }