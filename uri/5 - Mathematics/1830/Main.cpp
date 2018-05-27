#include <cstdio>
 
int main () {
        int x, y, z;
        float x1,y1,z1;
        int t=0;
        int esp = 0;
        int pred = 0, sort = 0;
        int croc = 0, misto = 0, trad = 0;
 
        scanf("%f %f %f", &x1, &y1, &z1);
 
 
        while (x1 != 0 || y1 != 0 || z1 != 0)
        {
            if (x1 >= 0 && y1 >= 0 && z1 >= 0 && x1 <=1000 && y1 <= 1000 && z1 <= 1000)
            {
 
                x = (int)(x1 * 1000);
                y = (int)(y1 * 1000);
                z = (int)(z1 * 1000);
 
                    if (x/5 < y/25 && x/5 < z/20)
                    {
                     croc = x/5;
                     x %= 5;
                     y -= croc*25;
                     z -= croc*20;
                    }
                    else if (y/25 < x/5 && y/25 < z/20)
                    {
                        croc = y/25;
                        y %= 25;
                        x -= croc*5;
                        z -= croc*20;
                    }
                    else
                    {
                     croc = z/20;
                     z %= 20;
                     x -= croc* 5;
                     y -= croc*25;
                    }
                    if ((z/25) <= (y/25))
                    {
                        misto = z/25;
                        z %= 25;
                        y -= misto*25;
                    }
                    else
                    {
                        misto = y/25;
                        y %= 25;
                        z -= misto*25;
                    }
 
                    trad = z/50;
 
                while ((croc - 10) >= 0 && (misto - 10) >= 0 && (trad-10) >= 0) //Sortido
                {
                    croc-=10;
                    misto-=10;
                    trad-=10;
                    sort++;
                }
                while ((croc-10) >= 0 && (misto-20) >= 0) //Predileta
                {
                    croc-=10;
                    misto-=20;
                    pred++;
                }
                while ((croc - 30) >= 0) //Especial
                {
                    croc -= 30;
                    esp++;
                }
 
                t++;
 
                printf("Caso #%d: %d Especial, %d Predileta e %d Sortida\n", t, esp, pred, sort);
 
                scanf("%f %f %f", &x1, &y1, &z1);
            }
            else
            {
                 scanf("%f %f %f", &x1, &y1, &z1);
            }
        }
    }