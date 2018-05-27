#include <cstdio>
#include <cstdlib>
#include <cmath>
 
int main(){
	int caso,bit,corte,mudarA,notMudarA,mudarB,notMudarB,i;
	double P,Q,PA,PB,PAUB;
	char gene1[10],gene2[10],gene3[10];
	scanf("%d",&caso);
	while(caso--){
		mudarA=notMudarA=mudarB=notMudarB=0;
		scanf("%d",&bit);
		scanf("%d %lf",&corte,&P);
		Q = 1 - P;
		scanf("%s %s %s",gene1,gene2,gene3);
		for(i=0;i<corte;i++){
			if(gene1[i] != gene3[i])
				mudarA++;
			else
				notMudarA++;
		}
 
		// printf("%d %d\n",mudarA,notMudarA);
 
		for(i=corte;i<bit;i++){
			if(gene2[i] != gene3[i])
				mudarA++;
			else
				notMudarA++;
		}
		// printf("%d %d\n",mudarA,notMudarA);
		PA = pow(P,mudarA) * pow(Q,notMudarA);
 
		for(i=corte;i<bit;i++){
			if(gene1[i] != gene3[i])
				mudarB++;
			else
				notMudarB++;
		}
 
		// printf("%d %d\n",mudarB,notMudarB);
 
		for(i=0;i<corte;i++){
			if(gene2[i] != gene3[i])
				mudarB++;
			else
				notMudarB++;
		}
		PB = pow(P,mudarB) * pow(Q,notMudarB); 
 
		PAUB = PA * PB;
		printf("%.7lf\n",PA + PB - PAUB);
	}
    return 0;
}