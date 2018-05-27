#include <iostream>
#include <stack>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

struct Point
{
        int x;
        int y;
};

Point p0;


Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
int dist(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

int compare(const void *vp1, const void *vp2)
{
    Point *p1 = (Point *) vp1;
    Point *p2 = (Point *) vp2;


    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (dist(p0, *p2) >= dist(p0, *p1)) ? -1 : 1;

    return (o == 2) ? -1 : 1;
}


vector<pair<int,int> >cords;


void convexHull(Point points[], int n)
{

    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;


        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }


    swap(points[0], points[min]);


    p0 = points[0];
    qsort(&points[1], n - 1, sizeof(Point), compare);

    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    for (int i = 3; i < n; i++)
    {

        while (orientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }


    while (!S.empty())
    {

        Point p = S.top();

        cords.push_back(make_pair(p.x,p.y));

        S.pop();
    }
}

double distancia(int x0,int y0,int x1,int y1)
{
    return sqrt(((x1 - x0)*(x1 - x0)) + ((y1 - y0)*(y1 - y0)));
}

int main()
{
    int N;
    while(scanf("%d",&N),N)
    {
        cords.clear();
        double Total = 0;
        Point points[2003];

        for(int i=0;i<N;i++)
            scanf("%d %d",&points[i].x,&points[i].y);


         convexHull(points, N);

        for(int i=0;i<cords.size();i++)
        {
            int x0 = cords[i].first;
            int y0 = cords[i].second;
            int x1,y1;
            if(i<cords.size()-1)
            {
                x1 = cords[i+1].first;
                y1 = cords[i+1].second;
            }
            else
            {
                x1 = cords[0].first;
                y1 = cords[0].second;
            }

            Total += distancia(x0,y0,x1,y1);

        }
        cout << "Tera que comprar uma fita de tamanho " << fixed<<setprecision(2) <<Total<<"."<<endl;
    }
    return 0;
}