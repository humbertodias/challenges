#include <stdio.h>
#include <math.h>
#define MAX 1001
int XB[MAX]; // puntos de borde
int YB[MAX];
int NB; // numero de puntos, o vertices
int XI[MAX]; // coordenadas de informantes
int YI[MAX];
int NI; // numero de informantes
int XR[MAX]; // centros de radares
int YR[MAX];
int RR[MAX]; // radios
int NR; // numero de radares
#define MAXC 40
int Ciclo[MAXC][MAX]; // arreglo para registrar "ciclos"
int tamCiclo[MAX]; // formados por centros de radares
int nCiclos;
int XC[MAXC][MAX]; // coordenadas de puntos de ciclos
int YC[MAXC][MAX];
// --------------------------------------------------------------------
int
entreYs(int y1, int y2, int y)
{
 if ( y1<=y && y<=y2 ) return 1;
 if ( y2<=y && y<=y1 ) return 1;
 return 0;
} 
// --------------------------------------------------------------------
int
obtieneX(int *X, int *Y, int i, int y)
{
 int m;
 m=(X[i+1]-X[i])/(Y[i+1]-Y[i]);
 return m*(y-Y[i])+X[i];
}
// --------------------------------------------------------------------
int
interior(int *X, int *Y, int N, int Xinf, int Yinf)
{
 int i,j,k;
 // abscisas de linea de rastreo Yinf con poligonal
 int xRastreo[MAX];
 int nR=0;
 int posmin, temp, resultado=0;
 // determinar lados cuyas ordenadas contienen Yinf
 for (i=0; i<N; i++)
 if ( entreYs(Y[i],Y[i+1],Yinf) ){
 if ( Y[i]==Y[i+1] ) {
 xRastreo[nR++]=X[i]; xRastreo[nR++]=X[i+1];
 } else xRastreo[nR++]=obtieneX(X,Y,i,Yinf);
}
 // ordenar xRastreo
 for (i=0; i<nR; i++) {
 posmin=i;
 for (j=i+1; j<nR; j++)
 if ( xRastreo[j]<xRastreo[posmin] ) {
 posmin=j; temp=xRastreo[i];
 xRastreo[i]=xRastreo[posmin]; xRastreo[posmin]=temp;
 }
 }
// Si Yinf coincide con un extremo de segmento que también es un extremo del siguiente segmento, tendremos dos puntos
// xRastreo idénticos. Por eso el siguiente código elimina los puntos de segmentos duplicados.
 for (i=0; i<nR; i++) { // eliminar los duplicados
 for (j=i+1; j<nR; j++)
 if ( xRastreo[i]==xRastreo[j] ) {
 for (k=j+1; k<nR; k++) xRastreo[k-1]=xRastreo[k];
 nR--;
 }
 }
 // detectar si punto (Xinf,Yinf) esta dentro de region
 for (i=0; i<nR-1; i++)
 // se determina si abscisa Xinf esta entre dos X consecutivos
 // si el indice i es par, el punto es interior (i empieza de 0)
 if ( xRastreo[i]<=Xinf && Xinf<=xRastreo[i+1] ) {
 if ( i%2 == 0 ) resultado=1; break;
 }
 return resultado;
}
// -------------------------------------------------------------------- 
int
DentroRadar(int Xinf, int Yinf)
{
 int i;
 double d;
 for (i=0; i<NR; i++) {
 d=sqrt( (XR[i]-Xinf)*(XR[i]-Xinf)+(YR[i]-Yinf)*(YR[i]-Yinf) );
 if ( d<=RR[i] ) return 1;
 }
 return 0;
}
// --------------------------------------------------------------------
int
estaEnCiclo(int radar)
{
 int i,j;
 for (i=0; i<nCiclos; i++)
 for (j=0; j<tamCiclo[i]; j++)
 if ( radar==Ciclo[i][j] ) return 1;
 return 0;
}
// --------------------------------------------------------------------
double
distPuntos(int x1, int y1, int x2, int y2)
{
 return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
// --------------------------------------------------------------------
int
centrosVecinos(int c1, int c2)
{
 if ( distPuntos(XR[c1],YR[c1],XR[c2],YR[c2]) <= (RR[c1]+RR[c2]) )
 return 1;
 return 0;
}
// --------------------------------------------------------------------
void
hallaCiclo(int radar)
{
 int CicloTemp[MAX];
 int nCentro, centro_ant, centro_sig, i;
 int agregado;
 CicloTemp[0]=radar; nCentro=1;
 // para simplificar se asumen ciclos disjuntos ...
 if ( estaEnCiclo(radar) ) return;
 agregado=1;
 while (1) {
 if ( !agregado ) break; // no se encontro ningun vecino
 centro_ant=CicloTemp[nCentro-1]; // de este radar partimos
 agregado=0;
 for (centro_sig=NR-1; centro_sig>radar; centro_sig--) { 
 for (i=0; i<nCentro; i++)
 if ( centro_sig==CicloTemp[i] ) break;
 if ( i<nCentro ) continue; // este ya esta en el ciclo
 if ( centrosVecinos(centro_ant,centro_sig) ) {
 agregado=1; CicloTemp[nCentro++]=centro_sig;
 centro_ant=centro_sig;
 }
 } // for sig
 } // while (1)
 if ( nCentro>=3 ) {
 centro_ant=CicloTemp[nCentro-1];
 centro_sig=CicloTemp[0];
 if ( centrosVecinos(centro_ant,centro_sig) ) {
 for (i=0; i<nCentro; i++) Ciclo[nCiclos][i]=CicloTemp[i];
 tamCiclo[nCiclos]=nCentro;
 nCiclos++;
 }
 }
}
// --------------------------------------------------------------------
void
creaCiclos(void)
{
 int i,j;
 nCiclos=0;
 for (i=0; i<NR; i++) hallaCiclo(i);
 for (i=0; i<nCiclos; i++) {
 for (j=0; j<tamCiclo[i]; j++) {
 XC[i][j]=XR[Ciclo[i][j]]; YC[i][j]=YR[Ciclo[i][j]];
 }
 XC[i][j]=XC[i][0]; YC[i][j]=YC[i][0];
 }
}
// --------------------------------------------------------------------
int
admisible(int inf) // prueba del informante inf
// Punto de informante es admisible
// si es interior a la region de borde,
// si no esta dentro del alcance de los radares, y
// si no es punto encerrado por uno de los ciclos de radares.
{
 int i;
 if ( !interior(XB,YB,NB,XI[inf],YI[inf]) ) return 0;
 if ( DentroRadar(XI[inf],YI[inf]) ) return 0;
 for (i=0; i<nCiclos; i++)
 if ( interior(XC[i],YC[i],tamCiclo[i],XI[inf],YI[inf]) ) return 0;
 return 1;
}
// -------------------------------------------------------------------- 

double
distanciaLado(int i, int x, int y)
{
 double lado, lado1, lado2, s;
 lado=distPuntos(XB[i],YB[i],XB[i+1],YB[i+1]);
 lado1=distPuntos(XB[i],YB[i],x,y);
 lado2=distPuntos(XB[i+1],YB[i+1],x,y);
 s=(x-XB[i]) * (YB[i+1]-YB[i]) - (y-YB[i]) * (XB[i+1]-XB[i]);
 if ( lado1>lado ) return lado2;
 if ( lado2>lado ) return lado1;
 s=(s>0)?s:(-s); // s es area del paralelogramo
 return (s/lado); // lado es la base, h=s/lado=altura
}
// --------------------------------------------------------------------
double
distanciaBorde(int x, int y)
{
 int i;
 double dmin, d;
 for (i=0; i<NB; i++) {
 d=distanciaLado(i,x,y);
 if ( i==0 || d<dmin) dmin=d;
 }
 return dmin;
}
// --------------------------------------------------------------------
int
main(void)
{
 int i,j,x,y,r,r_found,r_uniq;
 int inf;
 double distTEMP, distMAX;
 while(1) {
 scanf("%d", &NB);
 for (i=0; i<NB; i++) scanf("%d %d", XB+i, YB+i);
 scanf("%d", &NI);
 for (i=0; i<NI; i++) scanf("%d %d", XI+i, YI+i);
 scanf("%d", &NR);

 for (i=0; i<NR; i++) {
 scanf("%d %d %d", &x, &y, &r);
 if ( i==0 ) {
 XR[0]=x; YR[0]=y; RR[0]=r; r_uniq=1;
 } else {
 r_found=0; j=0;
 while ( !r_found && j<r_uniq ) {
 if ( x==XR[j] && y==YR[j] && r==RR[j] ) r_found=1;
 j++;
 }
 if ( !r_found ) {
 XR[r_uniq]=x; YR[r_uniq]=y; RR[r_uniq]=r;
 r_uniq++;
 } 
 }
 }
 if ( NR != 0 ) NR=r_uniq;
 if (NB==0 && NI==0 && NR==0) break;
 XB[NB]=XB[0]; YB[NB]=YB[0]; // cerrar borde
 creaCiclos();
 inf=-1;
 for (i=0; i<NI; i++) {
 if ( !admisible(i) ) continue;
 distTEMP=distanciaBorde(XI[i],YI[i]);
 if ( inf==-1 || distTEMP>distMAX ) {
 inf=i; distMAX=distTEMP;
 }
 }
 if (inf==-1) printf("Mission impossible\n");
 else printf("Contact informer %d\n", inf+1);
 }
} 