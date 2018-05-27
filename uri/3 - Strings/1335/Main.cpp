#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>

#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define clr(a, v) memset( a , v , sizeof(a) )
#define pb push_back
#define mp make_pair
#define sz size()
#define FORN( i , s , n ) for( int i = (s) ; i < (n) ; i++ )
#define FOR( i , n ) FORN( i , 0 , n )
#define FORIT( i , x ) for( typeof x.begin() i = x.begin() ; i != x.end() ; i++ )
#define trace(x)    cout << #x << ": " << x << endl;
#define trace2(x, y) cout << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define read ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;
 
#define INF 100000000 
 
typedef pair<int,int> ii;
typedef vector<int> vi; 
typedef vector<ii> vii; 
typedef long long int int64;
 
#define MAX 600100
 
string T;
int n;
int RA[MAX], tempRA[MAX];
int SA[MAX], tempSA[MAX];
int c[MAX];
int Phi[MAX], LCP[MAX], PLCP[MAX];
 
 
void countingSort(int k){
    int sum , maxi = max(300,n);
 
    clr(c,0);
 
    FOR(i,n) c[  ( i+k < n ) ? RA[i+k] : 0 ] ++;
 
 
    for(int i=sum=0; i<maxi; i++){
        int t = c[i]; c[i] =sum;sum+=t;
    }
 
    FOR(i,n ) tempSA[  c[ (SA[i]+k<n) ? RA[SA[i]+k]:0  ]++ ] = SA[i];
    FOR(i,n) SA[i] = tempSA[i];
 
}
 
 
void constructSA(){
    int r;
    FOR(i,n){ RA[i] = T[i]; SA[i]=i; } 
 
 
    for( int k = 1; k<n; k<<=1 ){
        countingSort(k);
        countingSort(0);
 
        tempRA[ SA[0] ]=r=0;
 
        FORN(i,1,n) tempRA[ SA[i] ] = (  RA[ SA[i] ] ==RA[ SA[i-1] ] && RA[ SA[i]+k ] ==RA[ SA[i-1]+k ]   )? r:++r;
        FOR(i,n) RA[i] = tempRA[i];
        if( RA[SA[n-1]] == n-1 ) break;
    }
 
}
 
void computeLCP(){
 
    Phi[SA[0]]=-1;
    FORN(i,1,n ) Phi[SA[i]]= SA[i-1];
 
    int L=0;
    FOR(i,n){
        if(Phi[i]==-1){ PLCP[i]=0; continue; }
 
        while( T[i+L]==T[ Phi[i]+L ] ) L++;
        PLCP[ i ] =L;
        L = max(L-1,0);
    }
    FOR(j,n) LCP[j] = PLCP[ SA[j] ]; 
 
}
 
char LT[MAX];
int L[MAX];
int P[MAX];
int64 X[MAX];
set<int64> S;
 
 
 
int padre(int u){
    return P[u] = (P[u]==u? u: padre(P[u])) ; 
} 
 
int unir( int u, int v ){
    int pu = padre(u);
    int pv = padre(v);
 
    if( pu==pv ) return 0;
 
    P[pu] = pv;
    X[pv] = X[pu]|X[pv];
    return 1;
}
 
int main(){
 
    char LT[10005];    
    int k;
 
    while(cin>>k and k){
 
        S.clear();
        T="";
        vi LL;
        char car=0;
        int ac=0;
        FOR(i,k){
            scanf("%s",LT);
            L[i] = strlen(LT)+1;
            ac += L[i];
            LL.pb(ac);
 
            T += string(LT);
            car++;
            T += car;
            n = T.sz;        
        }
 
        constructSA();
        computeLCP();
 
        vii E;
 
        FORN(i,k,n){
            if( LCP[i] ) E.pb( mp(LCP[i],i) );
            if( T[SA[i]]>62 ){
                E.pb( mp(*upper_bound(all(LL), SA[i] )-SA[i]-1 , -i) );    
            }
        }
        sort(all(E));
 
        FOR(i,n){
            X[i] = 1LL<<( upper_bound(all(LL), SA[i] )-LL.begin() );          
        }            
 
        FOR(i,n)  P[i] = i;
 
        reverse(all(E));
        vi pal;
 
        int i=0;
        for(int j = 10005 ; j>0; j--  ){
 
            while( i<E.sz and E[i].fst==j){
                ii pp = E[i];
 
                if(pp.snd<0){
                    pal.pb(-pp.snd);
                }
                else{
                    if( unir(pp.snd, pp.snd-1) )
                    pal.pb(pp.snd);
                }
 
                i++;
            }
 
            FOR(kk,pal.sz){
                S.insert( X[padre(pal[kk])] );
            }
            pal.clear();
        }
        cout<<S.sz<<endl;
 
    }           
 
    return 0;
}