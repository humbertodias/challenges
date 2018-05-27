#include <stdio.h>


int main(){

    float a,b,c,d,e,media;

    scanf("%f %f %f %f",&a,&b,&c,&d);

    media = (a*2 + b*3 + c*4 + d*1)/(10.0);
    printf("Media: %.1f\n", media);

    if(media >= 7.0)
            printf( "Aluno aprovado.\n");
    if(media < 5.0)
            printf( "Aluno reprovado.\n");
    if(media >= 5.0 && media < 7.0){
        printf( "Aluno em exame.\n");
        scanf("%f", &e);
        printf("Nota do exame: %.1f\n", e);
        if((media + e)/2.0 >= 5.0)
            printf( "Aluno aprovado.\n");
        else
            printf( "Aluno reprovado.\n");
        printf("Media final: %.1f\n", (media + e)/2.0 );
    }
    return 0;
}