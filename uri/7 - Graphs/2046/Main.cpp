#include <iostream>
#include <vector>
#include <cmath> // abs
#include <algorithm> // sort
#include <climits> // INT_MAX

using namespace std;
 
struct point
{
    int x;
    int y;
};
 
bool compare(point a, point b)
{
    if(a.x<b.x) return true;
    else if(a.x==b.x) return a.y<=b.y;
    return false;
}
 
int main() {
 
    int m,n;
    int cont=0;
 
    while(cin>>m>>n&&m&&n)
    {
        int k;
        cin >> k;
 
        vector<point> sedes;
 
        for(int i=0;i<k;i++)
        {
            point p;
            cin >> p.x >> p.y;
 
            sedes.push_back(p);
        }
 
        sort(sedes.begin(),sedes.begin()+k,compare);
 
        int l;
        cin >> l;
 
        cout << "Instancia " << ++cont << endl;
 
        for(int i=0;i<l;i++)
        {
            point p;
            cin >> p.x >> p.y;
 
            int menor = INT_MAX;
            point proximo;
 
            for(int j=0;j<k;j++)
            {
                if(abs(p.x-sedes[j].x)+abs(p.y-sedes[j].y)<menor)
                {
                    menor = abs(p.x-sedes[j].x)+abs(p.y-sedes[j].y);
                    proximo.x = sedes[j].x;
                    proximo.y = sedes[j].y;
                }
            }
 
            cout << proximo.x << " " << proximo.y << endl;
        }
        cout << endl;
    }
    return 0;
}