#include <stdio.h>
#include <string.h>
 
int comb[9][3] = {{0, 4, 8}, {0, 5, 7},
                  {1, 3, 8}, {1, 5, 6},
                  {2, 3, 7}, {2, 4, 6},
                  {0, 1, 2},
                  {3, 4, 5},
                  {6, 7, 8}};
 
int main (){
    int n, pi, si, t;
    int c[9];
    char str[12];
    while (scanf ("%d", &n), n){
        for (int i = 0; i < 9; i++)
            c[i] = 0;
        getchar();
        for (int i = 0; i < n; i++){
            scanf ("%s", str);
            if (!strcmp(str, "um"))
                pi = 0;
            else if (!strcmp(str, "dois"))
                pi = 1;
            else
                pi = 2;
            scanf ("%s", str);
            if (!strcmp(str, "triangulo") || !strcmp(str, "triangulos"))
                si = 0;
            else if (!strcmp(str, "circulo") || !strcmp(str, "circulos"))
                si = 3;
            else
                si = 6;
            c[pi + si]++;
        }
        t = 0;
        for (int i = 0; i < 9; i++)
            while(c[comb[i][0]] && c[comb[i][1]] && c[comb[i][2]]){
                t++;
                c[comb[i][0]]--; c[comb[i][1]]--; c[comb[i][2]]--;
            }
        for (int i = 0; i < 9; i++)
            if(c[i]/3 >= 1)
                t+= (c[i]/3);
        printf ("%d\n", t);
    }
}