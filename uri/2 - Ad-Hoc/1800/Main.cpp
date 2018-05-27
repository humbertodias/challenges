#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    int qtdOfficesWeek, qtdOfficesTwoDays;
    scanf("%d%d", &qtdOfficesWeek, &qtdOfficesTwoDays);

//    int offices[qtdOfficesWeek];
    int offices[qtdOfficesWeek+qtdOfficesTwoDays];
    int aux = 0;

    // Escritórios dos últimos dois dias são contados como visitados.
    for (int i = 0; i < qtdOfficesTwoDays; i++)
    {
        scanf("%d", &offices[i]);
        aux = i;
    }

    // Escritórios em que esteve toda a semana.
    for (int i = 0; i < qtdOfficesWeek; i++)
    {
        int office; scanf("%d", &office);
        bool found = false;

//        for (int j = 0; j < qtdOfficesWeek; j++)
        for (int j = 0; j <= aux; j++)
        {
            if (offices[j] == office)
            {
                printf("0\n");
                found = true;
                break;
            }
        }
        if (!found)
        {
            aux++;
            offices[aux] = office;
            printf("1\n");
        }
    }
}