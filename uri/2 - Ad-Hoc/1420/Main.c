#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
  int sem, dd, mes, sec, aa, hh, mm, ss;
} momento;

FILE *in, *out;
momento clock, acum;
int virames[12] = {132, 230, 332, 431, 532, 631,
       732, 832, 931, 1032, 1131, 1232};

void incdata(void){
  int i, j;
  acum.ss++;
  if (acum.ss==60) {
    acum.ss = 0;
    acum.mm++;
    if (acum.mm==60){
      acum.mm=0;
      acum.hh++;
      if (acum.hh==24){
  acum.hh = 0;
  acum.sem = (acum.sem + 1) % 7;
  acum.dd++;
  j = 100*acum.mes+acum.dd;
  for (i=0; (i<12) && (j != virames[i]) ; i++);
  if ((i<12) || ((j==229) && (acum.aa%4))){
    acum.dd = 1;
    acum.mes++;
    if (acum.mes==13){
      acum.mes = 1;
      acum.aa++;
    }
  }
      }
    }
  }
  return;
}


int main(){
  long x, y;
  int i, cont=0;
  char semx[7][4] = {"SAB", "DOM", "SEG", "TER", "QUA", "QUI", "SEX"};
  char mesx[12][4] = {"JAN", "FEV", "MAR", "ABR", "MAI", "JUN",
          "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"};

  char s1[4], m1[4], linha[256];

  in = stdin;
  out = stdout;

  while(42){
    fgets(&linha[0], 200, in);
    if (linha[0]=='F') break;
    for(i=0; i<3; i++) s1[i] = linha[i];
    s1[3] = '\0';
    for(i=0; (i<7) && (strcmp(s1, semx[i])); i++);
    if (i==7) { fprintf(stdout, "ERRO1\n"); exit(1); }
    else clock.sem = i;
    clock.dd = 10*(linha[4]-'0')+(linha[5]-'0');
    for(i=0; i<3; i++) m1[i] = linha[i+6];
    m1[3] = '\0';
    for(i=0; (i<12) && (strcmp(m1, mesx[i])); i++);
    if (i==12) { fprintf(stdout, "ERRO2\n"); exit(1); }
    else clock.mes = i+1;
    clock.sec = 20;
    clock.aa = 10*(linha[11]-'0')+(linha[12]-'0');
    clock.hh = 10*(linha[14]-'0')+(linha[15]-'0');
    clock.mm = 10*(linha[17]-'0')+(linha[18]-'0');
    clock.ss = 10*(linha[20]-'0')+(linha[21]-'0');
    fprintf(out, "Previsao #%d\n", ++cont);
    for(i=0; i<5; i++){
      acum.sem = clock.sem;
      acum.dd = clock.dd;
      acum.mes = clock.mes;
      acum.sec = clock.sec;
      acum.aa = clock.aa;
      acum.hh = clock.hh;
      acum.mm = clock.mm;
      acum.ss = clock.ss;
      fscanf(in, "%ld\n", &x);
      for(y=0; y<x; y++) incdata();
      fprintf(out, "%s,%02d%s%02d%02d:%02d:%02d:%02d\n",
  semx[acum.sem], acum.dd, mesx[acum.mes-1], acum.sec,
  acum.aa, acum.hh, acum.mm, acum.ss);
    }
  }
  fclose (in);
  return 1;
}
