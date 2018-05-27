#include <stdio.h>
 
int xCavalo,yCavalo;
int xPiao,yPiao;
int horizontalCavalo[] = {2, 2, -2, -2, 1, 1, -1, -1};
int verticalCavalo[] = {1, -1, 1, -1, 2, -2, 2, -2};
int tabuleiro[9][9];
void zerarTabuleiro()
{
    int i, j;
    for(i = 1; i <= 8; i++)
        for(j = 1; j <= 8; j++)
            tabuleiro[i][j] = 0;
}
void converte(char letra, int *x)
{
    if(letra >= 'a' && letra <= 'h'){
        switch(letra)
        {
            case 'a': *x = 1;break;
            case 'b': *x = 2;break;
            case 'c': *x = 3;break;
            case 'd': *x = 4;break;
            case 'e': *x = 5;break;
            case 'f': *x = 6;break;
            case 'g': *x = 7;break;
            case 'h': *x = 8;break;
        }
    }
    else
    {
         switch(letra)
        {
            case '1': *x = 8;break;
            case '2': *x = 7;break;
            case '3': *x = 6;break;
            case '4': *x = 5;break;
            case '5': *x = 4;break;
            case '6': *x = 3;break;
            case '7': *x = 2;break;
            case '8': *x = 1;break;
        }
    }
}
int main()
{
    char cavalo[2];
    char piao[2];
    int areaNaoAmeacada, casos = 0, i, j;
    while(scanf("%s", cavalo) && cavalo[0] != '0')
    {
        getchar();
        zerarTabuleiro();
        areaNaoAmeacada = 0;
        converte(cavalo[0], &xCavalo);
        converte(cavalo[1], &yCavalo);
        for(i = 0; i < 8; i++)
        {
            scanf("%s", piao);
            converte(piao[0], &xPiao);
            converte(piao[1], &yPiao);
            if(xPiao+1 <= 8 && yPiao+1 <= 8)
                tabuleiro[xPiao+1][yPiao+1] = 1;
            if(xPiao+1 <= 8 && yPiao-1 >= 1)
                tabuleiro[xPiao+1][yPiao-1] = 1;
        }
        for(j = 0; j < 8; j++){
            if(xCavalo+horizontalCavalo[j] <= 8 && xCavalo+horizontalCavalo[j] >= 1){
                if(yCavalo+verticalCavalo[j] <= 8 && yCavalo+verticalCavalo[j] >= 1)
                    if(tabuleiro[xCavalo+horizontalCavalo[j]][yCavalo+verticalCavalo[j]] != 1)
                        areaNaoAmeacada++;
            }
        }
        printf("Caso de Teste #%d: %d movimento(s).\n",++casos, areaNaoAmeacada);
    }
    return 0;
}