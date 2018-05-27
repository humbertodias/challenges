#include <vector>
#include <algorithm>
using namespace std;
 
class BinMatch {
    
    int     X,  Y,  M; 
    vector<vector<int> >   G;
    vector<int>     back;
    vector<bool>    mark;
    
    bool find( int v ) {
        for( int i = 0, w; i < G[v].size(); ++i ) {
            w = G[v][i]; 
            if( !mark[w] ) {
                mark[w] = true;
                if( back[w] == -1 || find( back[w] ) ) {
                    back[w] = v;
                    return  true;
                }
            }
        } 
        return  false;
    }
    
public:
    
    void init( int x, int y ) {
        X = x;  Y = y; 
        G.assign( X + 1, vector<int>( 0 ) );
    } 
    
    void insert( int v, int w ) { G[v].push_back( w ); }
    
    void run() {
        back.assign( Y + 1, -1 );
        for( int v = M = 0; v <= X; ++v ) {
            mark.assign( Y + 1, false ); 
            M += find( v );
        }
    } 
    
    int matchCnt() const { return M; }
    
    vector<pair<int, int> > getMatch() const {
        vector<pair<int, int> > ans;
        for( int i = 0; i < Y; ++i )
            if( back[i] != -1 )
                 ans.push_back( make_pair( back[i], i ) );
        return  ans;
    } 
    
}; 


#include <iostream>
#include <map>
#include <cstring> // memset
using namespace std;

int     N,  M,  K,  x,  y; 

bool    A[101][101];

map<pair<int, int>, int >    S1, S2;

int C1, C2;

BinMatch    binmatch;

int main() {

    while( cin >> N >> M && N ) {
        
        memset( A, 0, sizeof( A ) );
    
        for( cin >> K; K--; ) {
            scanf( "%d%d", &x, &y );
            A[x-1][y-1] = true;
        }
        
        C1 = C2 = 0;
        S1.clear();
        S2.clear();
        
        for( int i = 0; i < N; ++i ) {
            for( int j = 0; j < M; ++j ) {
                if( !A[i][j] ) {
                    if( ( i + j ) % 2 )
                        S1[make_pair( i, j )] = C1++;
                    else
                        S2[make_pair( i, j )] = C2++;
                }
            }
        }
        
        binmatch.init( C1, C2 );
        
        for( int i = 0; i < N; ++i ) {
            for( int j = 1; j < M; ++j ) {
                if( !A[i][j-1] && !A[i][j] ) {
                    if( ( i + j ) % 2 )
                        binmatch.insert( S1[make_pair(i,j)],
                                         S2[make_pair(i,j-1)] );
                    else
                        binmatch.insert( S1[make_pair(i,j-1)],
                                         S2[make_pair(i,j)] );
                }
            }
        }
        
        for( int i = 1; i < N; ++i ) {
            for( int j = 0; j < M; ++j ) {
                if( !A[i-1][j] && !A[i][j] ) {
                    if( ( i + j ) % 2 )
                        binmatch.insert( S1[make_pair(i,j)],
                                         S2[make_pair(i-1,j)] );
                    else
                        binmatch.insert( S1[make_pair(i-1,j)],
                                         S2[make_pair(i,j)] );
                }
            }
        }
        
        binmatch.run();
        cout << binmatch.matchCnt() << endl;
    
    }

}