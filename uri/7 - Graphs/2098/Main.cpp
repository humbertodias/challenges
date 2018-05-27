#include <cstdio>
#include <cstdlib>
using namespace std;
 
int n,m,i,j,k,x,y;
int h[505][505],dist[505][505];
int qx[1000005],qy[1000005],l,r;
bool inq[505][505];
 
void add(int x,int y,int d)
{
    if(dist[x][y]>=d)return;
    if(dist[x][y]==h[x][y])return;
    if(d<=h[x][y])dist[x][y]=d;
    else dist[x][y]=h[x][y];
    if(inq[x][y])return;
    ++r;if(r==1000000)r=1;
    qx[r]=x;qy[r]=y;inq[x][y]=true;
}
 
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
    for(j=1;j<=m;++j)
    scanf("%d",&h[i][j]),--h[i][j];
    qx[1]=n;qy[1]=m;l=0;r=1;
    for(i=1;i<=n;++i)
    for(j=1;j<=m;++j)
    dist[i][j]=-1;
    dist[n][m]=h[n][m];
    while(l!=r)
    {
        ++l;if(l==1000000)l=1;
        x=qx[l];y=qy[l];
        inq[x][y]=false;
        add(x-1,y,dist[x][y]-1);
        add(x+1,y,dist[x][y]-1);
        add(x,y-1,dist[x][y]-1);
        add(x,y+1,dist[x][y]-1);
    }
    printf("%d\n",dist[1][1]);
    return 0;
}