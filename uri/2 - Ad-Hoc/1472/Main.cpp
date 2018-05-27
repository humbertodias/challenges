#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int n, count, triangles;
    unsigned long points[100003], temp, interval, sum, p2, p3;
 
    while(scanf("%d", &n) != EOF)
    {
        sum = 0;
        triangles = 0;
        for( count = 0 ; count < n ; count++)
        {
            scanf("%lu", &temp);
            sum += temp;
            points[count] = sum;
        }
 
        if(sum%3 != 0)
            printf("0\n");
        else
        {
            interval = sum/3;
            for( count = 0 ; points[count] <= interval ; count++)
            {
                temp = points[count];
                p2 = temp+interval;
                p3 = temp+2*interval;
                if(binary_search(points + count + 1, points+n, p2) && binary_search(points + count + 1, points+n, p3) ) triangles++;
            }
            printf("%d\n", triangles);
        }        
    }
}