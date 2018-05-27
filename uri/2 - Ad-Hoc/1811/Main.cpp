#include <cstdio>

int main(int argc, char *argv[])
{
  int vet[1001][101], n, cont, m, max, imax, pmax, inic, i, j;
  FILE *ent;
  
  // ent = fopen("in.txt", "r");
  ent = stdin;
  if (ent == NULL) {
    printf("Arquivo de leitura não existe!");
    return 0;
  }
  fscanf(ent, "%d", &n);
  cont = 1;
  
  while (n != 0){
    printf("Instancia #%d\n", cont);
    cont++;
    fscanf(ent, "%d", &m);
    if (m == 0){ // caso que tenha certeza que o Pil vai querer tratar
      printf("1\n\n");
      fscanf(ent, "%d", &n);
    }
    else{
      
      /* daqui prá frente, m > 0 como em casos normais */
      max = 1; imax = 0; pmax = 0;
      
      for(i = 0; i <n ; i++){
  
  /* le os valores do i-esimo ator */
  for(j = 0; j < m; j++)
    fscanf(ent, "%d", &vet[i][j]);  
  /* calcula maior seq crescente do i-esimo ator */
  for (inic = 0; inic < m; inic++){
    
    j = inic;
    while(j < m-1 && vet[i][j+1] > vet[i][j]) j++;
    
    if (j - inic + 1 > max){
      max = j - inic + 1;
      imax = i;
      pmax = inic;
    }
    else if (j - inic + 1 == max){
      if (vet[i][j] - vet[i][inic] > vet[imax][pmax + max - 1] - vet[imax][pmax]){
        imax = i;
        pmax = inic;
      }
      
      else if (vet[i][j] - vet[i][inic] == vet[imax][pmax + max - 1] - vet[imax][pmax]){
        if (vet[i][j] > vet[imax][pmax + max - 1]){
    imax = i;
    pmax = inic;
        }
      }
    }
  }
      }
      
      printf("%d\n\n", imax + 1);
      fscanf(ent, "%d", &n);
    }
  }
  fclose(ent);
  return(0);
  
}