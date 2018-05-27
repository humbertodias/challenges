#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 100000000
#define MAXN 1100

struct ponto{
   int x, y, p;
   ponto(){}
   ponto( int xx, int yy, int pp ){
       x=xx; y=yy; p=pp;
   }
   void read(){
       scanf("%d %d %d",&x,&y,&p);   
   }
   bool operator != ( ponto p ){
       return (x != p.x || y != p.y);   
   }
   ponto operator - ( ponto p ){
       return ponto(x-p.x,y-p.y,this->p+p.p);   
   }
   long long operator * ( ponto p ) const{
       return ((long long)x)*p.y - ((long long)y)*p.x;
   }
   bool operator < ( ponto p ) const{
       if( half() != p.half() ){
           return (half() < p.half());
       }   
       else{
           return ((*this)*p > 0);
       }
   }
   int half() const{
       if( y>0 || (y==0 && x>0) ){
           return 0;   
       }   
       else{
           return 1;   
       }
   }
   
   bool coll ( ponto p ){
       return (half() == p.half() && (*this)*p==0);
   }
};

ponto p[2][MAXN];
int n, m, tam[2], resp;
vector<ponto> ord; //pontos ordenados por angulo
vector<ponto> sweep; //ordenação por angulo sem ponto colinear

void junta_colinear(){
   sweep.clear();
   for( int i=0 ; i<ord.size() ; i++ ){
       if( i==0 || !ord[i-1].coll(ord[i]) ){
           sweep.push_back(ord[i]);   
       }
       else{
           sweep.back().p += ord[i].p;   
       }
   }   
}

void line_sweep( ponto orig ){
   int i, j, pos, cnt, soma, soma_coll;
   ord.clear();
   orig.p = 0;
   for( j=0 ; j<2 ; j++ ){    
       for( i=0 ; i<tam[j] ; i++ ){
           if( p[j][i] != orig ){
               if( j==0 ){
                   ord.push_back(p[j][i]-orig);
               }   
               else{
                   ord.push_back(orig-p[j][i]);
               }
           }
       }
   }
   sort(ord.begin(),ord.end());
   junta_colinear();
   soma = pos = cnt = 0;
   for( i=0 ; i<sweep.size() ; i++ ){
       soma_coll = 0;
       while( sweep[i]*sweep[pos] >= 0 && cnt < sweep.size() ){
           if( sweep[i]*sweep[pos]==0 && sweep[i].half()!=sweep[pos].half() ){
               soma_coll = sweep[pos].p;
           }
           soma += sweep[pos].p;
           cnt++;
           pos = (pos+1)%sweep.size();
       }
       
       resp = min(resp,soma - soma_coll);
       resp = min(resp,soma - sweep[i].p);
       
       cnt--;
       soma -= sweep[i].p;
   }
}

int main(){
   int i, j;
   while( scanf("%d %d",&n,&m)>0 && !(n==0 && m==0) ){
       tam[0]=n;
       tam[1]=m;
       for( j=0 ; j<2 ; j++ ){    
           for( i=0 ; i<tam[j] ; i++ ){
               p[j][i].read();
           }
       }
       resp=INF;
       for( j=0 ; j<2 ; j++ ){    
           for( i=0 ; i<tam[j] ; i++ ){
               line_sweep(p[j][i]);
           }
       }
       printf("%d\n",resp);
   }
   return 0;   
}