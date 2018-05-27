#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MaxSe 40 + 1
#define MaxSum 80000 + 5

#define FOR(i, N) for( int i = 0 ; i < N ; i++ )

using namespace std;

int NumberOfTransaction, CashFlow;
int Sequence[MaxSe];
int Positive[MaxSe][MaxSum];
int Negative[MaxSe][MaxSum];
bool BPositive[MaxSe];
bool BNegative[MaxSe];

int Solve( int Index, int Sum, int CashF ){
    if ( Index == NumberOfTransaction )
        return Sum == CashF;
    int &NeGative = Negative[Index][Sum];
    int &PoSitive = Positive[Index][Sum];
    if ( NeGative != -1 && PoSitive != -1 )
        return NeGative || PoSitive;
    NeGative = 0;
    PoSitive = 0;
    
    if ( Sum + Sequence[Index] < MaxSum )
        PoSitive |= Solve(Index + 1, Sum + Sequence[Index], CashF);
    if ( Sum - Sequence[Index]  < MaxSum )
        NeGative |= Solve(Index + 1, Sum - Sequence[Index], CashF);
    if (NeGative)     BNegative[Index] = true;
    if (PoSitive)     BPositive[Index] = true;
    
    return NeGative || PoSitive;
    
}

int main(int argc, char** argv) {
    
    while ( scanf("%d %d", &NumberOfTransaction, &CashFlow), NumberOfTransaction|CashFlow ){
        FOR(i, NumberOfTransaction){
            scanf("%d", &Sequence[i]);
        }
        memset(BPositive, false, sizeof(BPositive));
        memset(BNegative, false, sizeof(BNegative));
        memset(Positive, -1, sizeof(Positive));
        memset(Negative, -1, sizeof(Negative));
        
        if ( !Solve(0, 0, CashFlow) ){
            puts("*");
        }else{
            FOR(i, NumberOfTransaction){
                if ( BNegative[i] && BPositive[i] )
                    printf("?");
                else if (BPositive[i])
                    printf("+");
                else if (BNegative[i])
                    printf("-");
            }
            puts("");
        }
            
        
        
    }

    return 0;
}