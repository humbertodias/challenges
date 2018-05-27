#include <stdio.h>
#include <string.h>

long long int modcp(char *pl){
    long long int mod=0;
    if ((int)pl[4]>64){ // placa nova
        //mod = 175759999+1; // ultima placa velha
        // numeros
        mod += ((int)pl[6]-48);
        mod += ((int)pl[5]-48)*10;
        // letras
        // constantes a multiplicar a cada nivel
        int v[] = {100, 2100, 44100, 926100, 19448100};
        int l,mul,j,i;
        // ultima letra = * 100
        j = 0;
        for (i=4; i>=0; i--){
            l = pl[i];
            mul = v[j];
            j++;
            if (l=='B'){ // == B
                mod += (l-1-'A')*mul;
            } else if (l<'I'){ // C < x < I
                mod += (l-2-'A')*mul;
            } else if (l<'M'){ // I < x < M
                mod += (l-3-'A')*mul;
            } else if (l<'P'){ // M < x < P
                mod += (l-4-'A')*mul;
            } else { // x > P
                mod += (l-5-'A')*mul;
            }
        }
    } else { // plana velha
        // numeros
        mod += ((int)pl[6]-48);
        mod += ((int)pl[5]-48)*10;
        mod += ((int)pl[4]-48)*100;
        mod += ((int)pl[3]-48)*1000;
        // letras
        mod += ((int)pl[2]-65)*10000;
        mod += ((int)pl[1]-65)*260000;
        mod += ((int)pl[0]-65)*6760000;
    }
    return mod;
}

int n(char a){
    return (a>='0' && a<='9');
}

int l(char a){
    return (a>='A' && a<='Z');
}

int l1(char a){
    if (a=='A' || a=='C' || a=='M' || a=='I' || a=='P')
        return 0;
    return (a>='A' && a<='Z');
}


int main(){
    int i;
    char s1[8],s2[8];
    int n1,n2,c,pau;
    char nc1[5],nc2[5];
    long long int diff;

    while (scanf("%s %s %d",s1,s2,&c)){
        if (!strcmp(s1,"*") && !strcmp(s2,"*") && c==0) break;
        
        pau = 0;
        if (!(l1(s2[0]) && l1(s2[1]) && l1(s2[2]) && l1(s2[3]) && 
            l1(s2[4]) && n(s2[5]) && n(s2[6])))
            if (!(l(s2[0]) && l(s2[1]) && l(s2[2]) && n(s2[3]) &&
                n(s2[4]) && n(s2[5]) && n(s2[6])))
                pau = 1;

        if (pau){
            printf("N\n");
            continue;
        }

        if ((int)s1[4]<58 && (int)s2[4]<58) // 2 velhas
            diff = modcp(s2)-modcp(s1);
        else if ((int)s1[4]>64 && (int)s2[4]>64) // 2 novas
            diff = modcp(s2)-modcp(s1);
        else if ((int)s1[4]<58) // primeira velha seg nova
            diff = (175759999-modcp(s1)+1)+modcp(s2);
        else // primeira nova segunda velha
            diff = 0;
 
        if (diff>0 && diff<=c)
            printf("Y\n");
        else
            printf("N\n");       
    }

    return 0;
}